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
        return true;
    }
    else if (direction == Turbohiker::LEFT and this->position.x > 0) {
        this->position.x--;
        return true;
    }
    return false;
}

Turbohiker::Entity::Entity(int lane) {
    this->position = Turbohiker::Position(lane, 0);
    this->speed = 3;
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