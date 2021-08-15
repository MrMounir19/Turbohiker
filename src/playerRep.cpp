#include "playerRep.h"


void PlayerRep::initTexture() {
    this->setTexture("Textures/player.png");
}

void PlayerRep::initSprite() {
    this->setSprite();
    //scale
    this->scaleSprite(3.f, 3.f);
    //createRect
    this->setTextureRect(sf::IntRect(64*this->getCounter(), 64*8, 64, 64));
}

PlayerRep::PlayerRep() : EntityRep() {
    this->initTexture();
    this->initSprite();   
}

void PlayerRep::update(Turbohiker::Position playerPosition) {
    this->setPositionSprite(sf::Vector2f(500.f + 225*playerPosition.x, 500.f));
    this->setTextureRect(sf::IntRect(64*int(this->getCounter()/5), 64*8, 64, 64));
    this->addCounter(1);
    this->moduloCounter(9*5);
}