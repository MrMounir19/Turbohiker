#include "bonusRep.h"

void BonusRep::initTexture() {
    this->setTexture("Textures/speedboost.png");
}

void BonusRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
}

void BonusRep::update(Turbohiker::Position position, Turbohiker::Position playerPosition, std::tuple<float,float> resRatio) {
    //SET POSITION
    this->setPositionSprite(sf::Vector2f((575.f + 225*position.x)*std::get<0>(resRatio), (500.f - (position.y-playerPosition.y)*2)*std::get<1>(resRatio)));
}

BonusRep::BonusRep(Turbohiker::BonusType type, std::tuple<float,float> resRatio) : EntityRep(resRatio) {
    this->initTexture();
    this->initSprite(resRatio);
    if (type == Turbohiker::spawn) {
        this->setTexture("Textures/spawnboost.png");
    }
    else {
        this->scaleSprite(0.1f*std::get<0>(resRatio), 0.1f*std::get<1>(resRatio));
    }
    this->type = type;
}

std::shared_ptr<EntityRep> BonusRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<BonusRep>(Turbohiker::speed, resRatio);
}