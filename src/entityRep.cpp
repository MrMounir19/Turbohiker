#include "entityRep.h"


EntityRep::EntityRep(std::tuple<float,float> resRatio) {
    this->animationCounter = 0;
}

void EntityRep::initTexture() {
    this->setTexture("Textures/player.png");
}

void EntityRep::initSprite(std::tuple<float,float> resRatio) {
    this->setSprite();
}

void EntityRep::setTexture(std::string filename) {
    this->texture.loadFromFile(filename);
}

void EntityRep::setSprite() {
    this->sprite.setTexture(this->texture);
}

void EntityRep::scaleSprite(float x, float y) {
    this->sprite.scale(x, y);
}

void EntityRep::setPositionSprite(sf::Vector2f position) {
    this->sprite.setPosition(position);
}

void EntityRep::move(float x, float y) {
    this->sprite.move(x, y);
}

void EntityRep::render(sf::RenderWindow& renderTarget) {
    renderTarget.draw(this->sprite);
}

void EntityRep::setTextureRect(sf::IntRect rect) {
    this->sprite.setTextureRect(rect);
}

int EntityRep::getCounter() {
    return this->animationCounter;
}

void EntityRep::addCounter(int amount) {
    this->animationCounter += amount;
}

void EntityRep::moduloCounter(int modulo) {
    this->animationCounter %= modulo;
}

std::shared_ptr<EntityRep> EntityRepFactory::createEntityRep(std::tuple<float,float> resRatio) {
    return std::make_shared<EntityRep>(resRatio);
}

