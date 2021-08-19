#include "enemyHikerRep.h"

void EnemyHikerRep::initTexture() {
    this->setTexture("Textures/enemyhikers.png");
}

void EnemyHikerRep::initSprite() {
    this->setSprite();
    this->scaleSprite(3.f, 3.f);
    this->setTextureRect(sf::IntRect(64*this->getCounter(), 64*2, 64, 64));
}

EnemyHikerRep::EnemyHikerRep() : EntityRep() {
    this->initTexture();
    this->initSprite();
}

void EnemyHikerRep::update(std::shared_ptr<Turbohiker::EnemyHiker>  hiker, Turbohiker::Position playerPosition) {
    if (!hiker->isActivated()) {
        //SET POSITION
        this->setPositionSprite(sf::Vector2f(500.f + 225*hiker->getPosition().x, 500.f - (hiker->getPosition().y-playerPosition.y)*2));
        if (hiker->getSpeed() == 0) {
            //SET ANIMATION
            this->setTextureRect(sf::IntRect(64*int(this->getCounter()/10), 64*2, 64, 64));
            //INCREASE COUNTER
            this->addCounter(1);
            this->moduloCounter(7*10);
        }
        else {
            //SET ANIMATION
            this->setTextureRect(sf::IntRect(64*int(this->getCounter()/10), 64*10, 64, 64));
            //INCREASE COUNTER
            this->addCounter(1);
            this->moduloCounter(9*10);
        }
    }
    else {
        if (hiker->getDirection() == Turbohiker::LEFT) {
            //SET POSITION
            this->setPositionSprite(sf::Vector2f(500.f + 225*hiker->getPosition().x, 500.f - (hiker->getPosition().y-playerPosition.y)*2));
            //MOVE
            this->move(10*hiker->getSpeed(), 0);
            hiker->setSpeed(hiker->getSpeed()+1);

            //SET ANIMATION
            this->setTextureRect(sf::IntRect(64*int(this->getCounter()/10), 64*9, 64, 64));
            //INCREASE COUNTER
            this->addCounter(1);
            this->moduloCounter(9*10);
        }
        else {
            //SET POSITION
            this->setPositionSprite(sf::Vector2f(500.f + 225*hiker->getPosition().x, 500.f - (hiker->getPosition().y-playerPosition.y)*2));
            this->move(10*hiker->getSpeed(), 0);
            hiker->setSpeed(hiker->getSpeed()+1);
            //SET ANIMATION
            this->setTextureRect(sf::IntRect(64*int(this->getCounter()/10), 64*11, 64, 64));
            //INCREASE COUNTER
            this->addCounter(1);
            this->moduloCounter(9*10);
        }
    }
}

