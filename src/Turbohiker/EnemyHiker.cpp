#include "EnemyHiker.h"

Turbohiker::EnemyHiker::EnemyHiker(int lane, int position, int speed) : Entity(lane, position) {
    this->setSpeed(speed);
    this->leavingDirection = Turbohiker::LEFT;
    this->activated = false;
}


bool Turbohiker::EnemyHiker::isActivated() {
    return this->activated;
}

void Turbohiker::EnemyHiker::activate() {
    this->setSpeed(1);
    if (this->getPosition().x >= 2) {
        this->leavingDirection = Turbohiker::RIGHT;
    }
    this->activated = true;
}

Turbohiker::Direction Turbohiker::EnemyHiker::getDirection() {
    return this->leavingDirection;
}

void Turbohiker::EnemyHiker::update() {
    if (!this->activated) {
        this->setPosition(this->getPosition().x, this->getPosition().y+this->getSpeed());
        this->setUpdated(true);
    }
}