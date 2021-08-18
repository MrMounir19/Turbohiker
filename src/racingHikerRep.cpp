#include "racingHikerRep.h"

void RacingHikerRep::initTexture() {
    this->setTexture("Textures/racinghikers.png");
}

void RacingHikerRep::initSprite() {
    this->setSprite();
    this->scaleSprite(3.f, 3.f);
    this->setTextureRect(sf::IntRect(64*this->getCounter(), 64*8, 64, 64));
}

RacingHikerRep::RacingHikerRep() : EntityRep() {
    this->initTexture();
    this->initSprite();
}

void RacingHikerRep::update(Turbohiker::Position position, Turbohiker::Position playerPosition) {
    //SET POSITION
    this->setPositionSprite(sf::Vector2f(500.f + 225*position.x, 500.f - (position.y-playerPosition.y)*2));
    //SET ANIMATION
    this->setTextureRect(sf::IntRect(64*int(this->getCounter()/5), 64*8, 64, 64));
    //INCREASE COUNTER
    this->addCounter(1);
    this->moduloCounter(9*5);
}