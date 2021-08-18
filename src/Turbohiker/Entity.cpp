#include "Entity.h"

unsigned int Turbohiker::Entity::getSpeed() {
    return this->speed;
}

Turbohiker::Position Turbohiker::Entity::getPosition() {
    return this->position;
};

bool Turbohiker::Entity::changeLane(Turbohiker::Direction direction) {
    if (direction == Turbohiker::RIGHT and this->position.x < 3) {
        this->position.x++;
        this->setUpdated(true);
        return true;
    }
    else if (direction == Turbohiker::LEFT and this->position.x > 0) {
        this->position.x--;
        this->setUpdated(true);
        return true;
    }
    return false;
}

Turbohiker::Entity::Entity(int lane, int position) {
    this->position = Turbohiker::Position(lane, position);
    this->speed = 2;
}

void Turbohiker::Entity::increaseSpeed() {
    if (this->speed < 4) {
        this->speed++;
    }
}

void Turbohiker::Entity::decreaseSpeed() {
    if (this->speed > 1) {
        this->speed--;
    }
}

void Turbohiker::Entity::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void Turbohiker::Entity::setSpeed(unsigned speed) {
    this->speed = speed;
}

void Turbohiker::Entity::update() {
    if (!this->getUpdated()) {
        this->setPosition(this->getPosition().x, this->getPosition().y+this->getSpeed());
        this->setUpdated(true);
    }
}

bool Turbohiker::Entity::getUpdated() {
    return this->updated;
}

void Turbohiker::Entity::setUpdated(bool update) {
    this->updated = updated;
}