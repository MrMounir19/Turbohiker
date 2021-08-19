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
}

Turbohiker::Game::~Game() {

}

void Turbohiker::Game::update() {
    //UPDATE PLAYER
    this->updateEntity(this->player);

    //UPDATE AI
    for (auto& ai:this->AI) {
        this->updateEntity(ai);
    }
    for (auto& enemy:this->world->getEnemyHikers()) {
        enemy->update();
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
    Turbohiker::Position oldPosition = entity->getPosition();
    entity->update();
    //CHECK COLLISION
    if (checkCollision(entity, oldPosition)) {
        entity->setPosition(oldPosition.x, oldPosition.y);
        entity->setSpeed(1);
    }
    //CHECK BONUS COLLECTED
    /*
    Bonus* bonus = checkCollectedBonus(entity, oldPosition);
    if (bonus) {
        entity->applyBonus(bonus);
    }
    */
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

/*
Turbohiker::Bonus* Turbohiker::Game::checkCollectedBonus(Entity* hiker, Turbohiker::Position oldPosition) {
    for (auto& bonus:this->world->getBonuses()) {
        if (bonus->getPosition().x == hiker->getPosition().x and Turbohiker::betweenRange(oldPosition, bonus->getPosition(), hiker->getPosition())) {
            return bonus;
        }
    }
}
*/
