#include "finishLineRep.h"

void FinishLineRep::initTexture() {
    this->setTexture("Textures/finishLine.png");
}

void FinishLineRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
    this->scaleSprite(2*std::get<0>(resRatio), 1*std::get<1>(resRatio));
}


void FinishLineRep::update(Turbohiker::Position playerPosition, std::tuple<float,float> resRatio) {
    this->setPositionSprite(sf::Vector2f((500.f + 225*0)*std::get<0>(resRatio), 500.f - ((3500-playerPosition.y)*2)*std::get<1>(resRatio)));
}

FinishLineRep::FinishLineRep(std::tuple<float,float> resRatio) : EntityRep(resRatio) {
    this->initTexture();
    this->initSprite(resRatio);   
}

std::shared_ptr<EntityRep> FinishLineRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<FinishLineRep>(resRatio);
}