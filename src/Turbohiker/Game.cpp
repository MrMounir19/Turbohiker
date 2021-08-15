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
    Turbohiker::Position oldPosition = this->player->getPosition();
    this->player->advance();
    //CHECK COLLISION
    if (checkCollision(this->player)) {
        this->player->setPosition(oldPosition.x, oldPosition.y);
        this->player->setSpeed(1);
    }

    //UPDATE AI
    for (auto& ai:this->AI) {
        Turbohiker::Position oldPosition = this->player->getPosition();
        ai->advance();
        //CHECK COLLISION
        if (checkCollision(ai)) {
            ai->setPosition(oldPosition.x, oldPosition.y);
            ai->setSpeed(1);
        }
    }

    
    //UPDATE OBSTACLES

}


bool Turbohiker::Game::checkCollision(Entity* hiker) {
    for (auto& ai:this->AI) {
        if (ai != hiker and ai->getPosition() == hiker->getPosition()) {
            return true;
        }
    }
    if (this->player != hiker and this->player->getPosition() == hiker->getPosition()) {
        return true;
    }

    return false;
}


bool Turbohiker::Game::changeLane(Turbohiker::Direction direction, Turbohiker::Entity* hiker) {
    Turbohiker::Position oldPosition = hiker->getPosition();
    if (hiker->changeLane(direction)) {
        if (this->checkCollision(hiker)) {
            hiker->setPosition(oldPosition.x, oldPosition.y);
            hiker->setSpeed(1);
        }
    }
}
