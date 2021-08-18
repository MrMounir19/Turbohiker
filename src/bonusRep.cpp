#include "bonusRep.h"

void BonusRep::initTexture() {
    this->setTexture("Textures/speedboost.png");
}

void BonusRep::initSprite() {
    this->setSprite();
    this->scaleSprite(0.1f, 0.1f);
}

void BonusRep::update(Turbohiker::Position position, Turbohiker::Position playerPosition) {
    //SET POSITION
    this->setPositionSprite(sf::Vector2f(575.f + 225*position.x, 500.f - (position.y-playerPosition.y)*2));
}


BonusRep::BonusRep(Turbohiker::BonusType type) : EntityRep() {
    this->initTexture();
    this->initSprite();
    this->type = type;
}