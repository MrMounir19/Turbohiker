#include "backgroundRep.h"

void BackgroundRep::initTexture() {
    this->setTexture("Textures/highway.png");
}

void BackgroundRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
    this->scaleSprite(std::get<0>(resRatio), std::get<1>(resRatio));
}

void BackgroundRep::update(unsigned int playerSpeed, std::tuple<float,float> resRatio) {
    this->setTextureRect(sf::IntRect(0, 1079-this->getCounter(), 1920, 1080));
    this->addCounter((4*playerSpeed));
    this->moduloCounter(1080);
}

BackgroundRep::BackgroundRep(std::tuple<float,float> resRatio) : EntityRep(resRatio) {
    this->initTexture();
    this->initSprite(resRatio);
}

std::shared_ptr<EntityRep> BackgroundRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<BackgroundRep>(resRatio);
}