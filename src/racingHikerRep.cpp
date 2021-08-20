#include "racingHikerRep.h"

void RacingHikerRep::initTexture() {
    this->setTexture("Textures/racinghikers.png");
}

void RacingHikerRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
    this->scaleSprite(3.f*std::get<0>(resRatio), 3.f*std::get<1>(resRatio));
    this->setTextureRect(sf::IntRect(64*this->getCounter(), 64*8, 64, 64));
}

RacingHikerRep::RacingHikerRep(std::tuple<float,float> resRatio) : EntityRep(resRatio) {
    this->initTexture();
    this->initSprite(resRatio);
}

void RacingHikerRep::update(Turbohiker::Position position, Turbohiker::Position playerPosition, std::tuple<float,float> resRatio) {
    //SET POSITION
    this->setPositionSprite(sf::Vector2f((500.f + 225*position.x)*std::get<0>(resRatio), 500.f - ((position.y-playerPosition.y)*2)*std::get<1>(resRatio)));
    //SET ANIMATION
    this->setTextureRect(sf::IntRect(64*int(this->getCounter()/5), 64*8, 64, 64));
    //INCREASE COUNTER
    this->addCounter(1);
    this->moduloCounter(9*5);
}

std::shared_ptr<EntityRep> RacinHikerRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<RacingHikerRep>(resRatio);
}