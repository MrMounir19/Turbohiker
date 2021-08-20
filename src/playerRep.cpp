#include "playerRep.h"


void PlayerRep::initTexture() {
    this->setTexture("Textures/player.png");
}

void PlayerRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
    //scale
    this->scaleSprite(3.f*std::get<0>(resRatio), 3.f*std::get<1>(resRatio));
    //createRect
    this->setTextureRect(sf::IntRect(64*this->getCounter(), 64*8, 64, 64));
}

PlayerRep::PlayerRep(std::tuple<float,float> resRatio) : EntityRep(resRatio) {
    this->initTexture();
    this->initSprite(resRatio);   
}

void PlayerRep::update(Turbohiker::Position playerPosition, std::tuple<float,float> resRatio) {
    
    this->setPositionSprite(sf::Vector2f((500.f + 225*playerPosition.x)*std::get<0>(resRatio), 500.f*std::get<1>(resRatio)));
    this->setTextureRect(sf::IntRect(64*int(this->getCounter()/5), 64*8, 64, 64));
    this->addCounter(1);
    this->moduloCounter(9*5);
}

std::shared_ptr<EntityRep> PlayerRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<PlayerRep>(resRatio);
}