#include "Game.h"

Turbohiker::Player* Turbohiker::Game::getPlayer() {
    return this->player;
}

std::vector<Turbohiker::RacingHiker*> Turbohiker::Game::getAI() {
    return this->AI;
}

void Turbohiker::Game::initPlayer() {
    srand(time(NULL));
    //GENERATE RANDOM LANE
    int lane = rand() % 4;
    //ADD PLAYER
    this->player = new Player(lane);
}

void Turbohiker::Game::initAI() {
    for (int i = 0; i < 4; i++) {
        if (i != this->player->getPosition().x) {
            this->AI.push_back(new RacingHiker(i));
        }
    }
}

void Turbohiker::Game::initWorld() {
    world = new World();
} 

Turbohiker::Game::Game() {
    this->initPlayer();
    this->initAI();
    this->initWorld();
}

Turbohiker::Game::~Game() {
    delete this->player;
    this->AI.clear();
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

bool Turbohiker::Game::checkCollision(Entity* hiker, Turbohiker::Position oldPosition) {
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

bool Turbohiker::Game::changeLane(Turbohiker::Direction direction, Turbohiker::Entity* hiker) {
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

void Turbohiker::Game::updateEntity(Entity* entity) {
    Turbohiker::Position oldPosition = entity->getPosition();
    entity->update();
    //CHECK COLLISION
    if (checkCollision(entity, oldPosition)) {
        entity->setPosition(oldPosition.x, oldPosition.y);
        entity->setSpeed(1);
    }
}

Turbohiker::World* Turbohiker::Game::getWorld() {
    return this->world;
}
