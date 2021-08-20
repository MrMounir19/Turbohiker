#include "enemyHikerRep.h"

void EnemyHikerRep::initTexture() {
    this->setTexture("Textures/enemyhikers.png");
}

void EnemyHikerRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
    this->scaleSprite(3.f*std::get<0>(resRatio), 3.f*std::get<1>(resRatio));
    this->setTextureRect(sf::IntRect(64*this->getCounter(), 64*2, 64, 64));
}

EnemyHikerRep::EnemyHikerRep(std::tuple<float,float> resRatio) : EntityRep(resRatio) {
    this->initTexture();
    this->initSprite(resRatio);
}

void EnemyHikerRep::update(std::shared_ptr<Turbohiker::EnemyHiker>  hiker, Turbohiker::Position playerPosition, std::tuple<float,float> resRatio) {
    if (!hiker->isActivated()) {
        //SET POSITION
        this->setPositionSprite(sf::Vector2f((500.f + 225*hiker->getPosition().x)*std::get<0>(resRatio), 
            (500.f - (hiker->getPosition().y-playerPosition.y)*2)*std::get<1>(resRatio)));
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
            this->setPositionSprite(sf::Vector2f((500.f + 225*hiker->getPosition().x)*std::get<0>(resRatio), 
                (500.f - (hiker->getPosition().y-playerPosition.y)*2)*std::get<1>(resRatio)));
            //MOVE
            this->move(10*hiker->getSpeed()*std::get<0>(resRatio), 0);
            hiker->setSpeed(hiker->getSpeed()+1);

            //SET ANIMATION
            this->setTextureRect(sf::IntRect(64*int(this->getCounter()/10), 64*11, 64, 64));
            //INCREASE COUNTER
            this->addCounter(1);
            this->moduloCounter(9*10);
        }
        else {
            //SET POSITION
            this->setPositionSprite(sf::Vector2f((500.f + 225*hiker->getPosition().x)*std::get<0>(resRatio), 
                (500.f - (hiker->getPosition().y-playerPosition.y)*2)*std::get<1>(resRatio)));
            this->move(10*hiker->getSpeed()*std::get<0>(resRatio), 0);
            hiker->setSpeed(hiker->getSpeed()+1);
            //SET ANIMATION
            this->setTextureRect(sf::IntRect(64*int(this->getCounter()/10), 64*11, 64, 64));
            //INCREASE COUNTER
            this->addCounter(1);
            this->moduloCounter(9*10);
        }
    }
}

std::shared_ptr<EntityRep> EnemyHikerRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<EnemyHikerRep>(resRatio);
}