#include "backgroundRep.h"

void BackgroundRep::initTexture() {
    this->setTexture("Textures/highway.png");
}

void BackgroundRep::initSprite() {
    this->setSprite();
}

void BackgroundRep::update(unsigned int playerSpeed) {
    this->setTextureRect(sf::IntRect(0, 1079-this->getCounter(), 1920, 1080));
    this->addCounter((4*playerSpeed));
    this->moduloCounter(1080);
}

BackgroundRep::BackgroundRep() : EntityRep() {
    this->initTexture();
    this->initSprite();
}
