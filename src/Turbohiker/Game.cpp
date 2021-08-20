#include "Game.h"

std::shared_ptr<Turbohiker::Player> Turbohiker::Game::getPlayer() {
    return this->player;
}

std::vector<std::shared_ptr<Turbohiker::RacingHiker>> Turbohiker::Game::getAI() {
    return this->AI;
}

void Turbohiker::Game::initPlayer() {
    Turbohiker::RandomSingleton* X = Turbohiker::RandomSingleton::getInstance();
    //GENERATE RANDOM LANE
    double lane = X->random(0, 3);

    //CREATE FACTORY
    std::unique_ptr<PlayerFactory> playerFactory = std::make_unique<PlayerFactory>();

    //ADD PLAYER
    this->player = std::dynamic_pointer_cast<Player>(playerFactory->createEntity(lane, 0));
}

void Turbohiker::Game::initAI() {
    //CREATE FACTORY
    std::unique_ptr<RacinghikerFactory> racinghikerFactory = std::make_unique<RacinghikerFactory>();

    for (int i = 0; i < 4; i++) {
        if (i != this->player->getPosition().x) {
            this->AI.push_back(std::dynamic_pointer_cast<RacingHiker>(racinghikerFactory->createEntity(i, 0)));
        }
    }
}

void Turbohiker::Game::initWorld() {
    std::unique_ptr<WorldFactory> worldFactory = std::make_unique<WorldFactory>();
    this->world = worldFactory->createWorld();
} 

Turbohiker::Game::Game() {
    this->initPlayer();
    this->initAI();
    this->initWorld();
    this->clock = 0;
    this->running = true;
}

Turbohiker::Game::~Game() {

}

void Turbohiker::Game::update() {
    clock++;
    //UPDATE PLAYER
    this->updateEntity(this->player);

    //UPDATE AI
    for (auto& ai:this->AI) {
        this->updateEntity(ai);
    }
    for (auto& enemy:this->world->getEnemyHikers()) {
        enemy->update();
    }
    //check if game finished
    this->running = false;
    for (auto& ai:this->AI) {
        if (ai->getSpeed() != 0) {
            this->running = true;
            break;
        }
    }
    if (player->getSpeed() != 0) {
        this->running = true;
    }
}

bool Turbohiker::Game::checkCollision(std::shared_ptr<Entity> hiker, Turbohiker::Position oldPosition) {
    for (auto& ai:this->AI) {
        if (ai != hiker and ai->getPosition().x == hiker->getPosition().x and 
            Turbohiker::betweenRange(oldPosition, ai->getPosition(), hiker->getPosition())) {
            return true;
        }
    }

    for (auto& staticHiker:this->world->getEnemyHikers()) {
        if (staticHiker != hiker and staticHiker->getPosition().x == hiker->getPosition().x and 
            Turbohiker::betweenRange(oldPosition, staticHiker->getPosition(), hiker->getPosition()) and !staticHiker->isActivated()) {
            staticHiker->activate();
            return true;
        }
    }

    if (this->player != hiker and this->player->getPosition().x == hiker->getPosition().x and
            Turbohiker::betweenRange(oldPosition, this->player->getPosition(), hiker->getPosition())) {
        return true;
    }

    return false;
}

bool Turbohiker::Game::changeLane(Turbohiker::Direction direction, std::shared_ptr<Entity> hiker) {
    Turbohiker::Position oldPosition = hiker->getPosition();
    if (hiker->changeLane(direction)) {
        if (this->checkCollision(hiker, oldPosition)) {
            hiker->setPosition(oldPosition.x, oldPosition.y);
            hiker->setSpeed(1);
        }
    }
}

void Turbohiker::Game::removeUpdates() {
    this->player->setUpdated(false);
    for (auto& ai:this->AI) {
        ai->setUpdated(false);
    }
    for (auto& enemy:this->world->getEnemyHikers()) {
        enemy->setUpdated(false);
    }
}

void Turbohiker::Game::updateEntity(std::shared_ptr<Entity> entity) {
    if (entity->getSpeed() != 0) {
        Turbohiker::Position oldPosition = entity->getPosition();
        entity->update();
        //CHECK COLLISION
        if (checkCollision(entity, oldPosition)) {
            entity->setPosition(oldPosition.x, oldPosition.y);
            entity->setSpeed(1);
            entity->addMinusPoint();
        }

        //CHECK BONUS COLLECTED
        std::shared_ptr<Bonus> bonus = checkCollectedBonus(entity, oldPosition);
        if (bonus) {
            entity->applyBonus(bonus);
            //BOTS ACTIVATE ACTIVE BONUS DIRECTLY
            if (entity != player and bonus->getType()==Turbohiker::spawn and entity->getActiveBonus()) {
                this->activateBonus(entity);
            }
        }
        if (entity->getPosition().y >= 3488) {
            entity->setSpeed(0);
            entity->setPosition(entity->getPosition().x, 3500);
            if (entity == player) {
                this->playerScore = 100 - this->AIScores.size()*10 - entity->getMinusPoints();
            }
            else {
                int score = 100 - this->AIScores.size()*10 - entity->getMinusPoints();
                if (this->player->getSpeed() == 0) {
                    score = score-10;
                }
                AIScores.push_back(score);
            }
        }
    }
}

std::shared_ptr<Turbohiker::World> Turbohiker::Game::getWorld() {
    return this->world;
}

void Turbohiker::Game::yell(std::shared_ptr<Entity> hiker) {
    if (hiker->getYellCooldown() <= 0) {
        //YELL
        std::shared_ptr<Turbohiker::EnemyHiker> closestEnemy = this->closestEnemy(hiker);
        if (closestEnemy) {
            closestEnemy->getYelled();
            hiker->setUpdated(true);
            hiker->resetYellCooldown();
            hiker->addMinusPoint();
        }
    }
}

std::shared_ptr<Turbohiker::EnemyHiker> Turbohiker::Game::closestEnemy(std::shared_ptr<Entity> hiker) {
    std::shared_ptr<Turbohiker::EnemyHiker> closestEnemy = nullptr;
    Turbohiker::Position position = hiker->getPosition();
    for (auto& enemy:this->getWorld()->getEnemyHikers()) {
        if (position.x == enemy->getPosition().x && position.y < enemy->getPosition().y &&
            position.y + 200 > enemy->getPosition().y) {
                if (closestEnemy) {
                    if (closestEnemy->getPosition().y > enemy->getPosition().y) {
                        closestEnemy = enemy;
                    }
                }
                else {
                    closestEnemy = enemy;
                }
        }
    }
    return closestEnemy;
}

std::shared_ptr<Turbohiker::Bonus> Turbohiker::Game::checkCollectedBonus(std::shared_ptr<Entity> hiker, Turbohiker::Position oldPosition) {
    for (auto& bonus:this->world->getBonuses()) {
        if (bonus->getPosition().x == hiker->getPosition().x and Turbohiker::betweenRange(oldPosition, bonus->getPosition(), hiker->getPosition())) {
            return bonus;
        }
    }
    return nullptr;
}

std::unique_ptr<Turbohiker::Game> Turbohiker::GameFactory::createGame() {
    return std::make_unique<Turbohiker::Game>();
}

void Turbohiker::Game::activateBonus(std::shared_ptr<Turbohiker::Entity> hiker) {
    std::shared_ptr<Turbohiker::Bonus> bonus = hiker->getActiveBonus();
    if (bonus) {
        if (bonus->getType() == Turbohiker::spawn) {
            bonus->activate();
            bonus->removeFromRoad();
            Turbohiker::RandomSingleton* X = Turbohiker::RandomSingleton::getInstance();
            double x = X->random(0, 1);
            std::shared_ptr<EnemyHiker> newEnemy = std::make_shared<EnemyHiker>(hiker->getPosition().x, hiker->getPosition().y-1);

            if (x < 0.5) {  // 50% CHANCE TO BE A MOVING ENEMY
                newEnemy->setSpeed(-2);
            }
            this->getWorld()->addEnemy(newEnemy);
            hiker->setActiveBonus(nullptr);
        }
    }
}

bool Turbohiker::Game::isRunning() {
    return this->running;
}

int Turbohiker::Game::getPlayerScore() {
    return this->playerScore;
}

std::vector<int> Turbohiker::Game::getAIScores() {
    return this->AIScores;
}