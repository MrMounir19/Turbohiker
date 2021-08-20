#include "Entity.h"

int Turbohiker::Entity::getSpeed() {
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
    this->yellCooldown = 180;
    this->maxSpeed = 2;
}

void Turbohiker::Entity::increaseSpeed() {
    if (this->speed < maxSpeed) {
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

void Turbohiker::Entity::setSpeed(int speed) {
    this->speed = speed;
}

void Turbohiker::Entity::update() {
    if (!this->getUpdated()) {
        this->setPosition(this->getPosition().x, this->getPosition().y+this->getSpeed());
        this->decreaseYellCooldown();
        if (passiveBonus) {
            passiveBonus->reduceDuration();
            if (passiveBonus->getDuration() <= 0) {
                this->removePassiveBonus();
            }
        }
        this->setUpdated(true);
    }
}

bool Turbohiker::Entity::getUpdated() {
    return this->updated;
}

void Turbohiker::Entity::setUpdated(bool update) {
    this->updated = updated;
}


int Turbohiker::Entity::getYellCooldown() {
    return this->yellCooldown;
}
void Turbohiker::Entity::resetYellCooldown() {
    this->yellCooldown = 500;
}

void Turbohiker::Entity::decreaseYellCooldown() {
    this->yellCooldown--;
}

void Turbohiker::Entity::upgradeMaxSpeed() {
    this->maxSpeed = 3;
}

void Turbohiker::Entity::resetMaxSpeed() {
    this->maxSpeed = 2;
}

void Turbohiker::Entity::setActiveBonus(std::shared_ptr<Bonus> bonus) {
    this->activeBonus = bonus;
}
void Turbohiker::Entity::setPassiveBonus(std::shared_ptr<Bonus> bonus) {
    this->passiveBonus = bonus;
}

std::shared_ptr<Turbohiker::Bonus> Turbohiker::Entity::getActiveBonus() {
    return this->activeBonus;
}
std::shared_ptr<Turbohiker::Bonus> Turbohiker::Entity::getPassiveBonus() {
    return this->passiveBonus;
}

void Turbohiker::Entity::applyBonus(std::shared_ptr<Turbohiker::Bonus> bonus) {
    //PASSIVE
    if (bonus->getType() == Turbohiker::speed) {
        if (this->passiveBonus) {
            this->removePassiveBonus();
        }
        this->passiveBonus = bonus;
        this->maxSpeed = 3;
        this->setSpeed(3);
        bonus->removeFromRoad();
        bonus->activate();
    }

    //ACTIVE
    else if (bonus->getType() == Turbohiker::spawn) {
        if (!this->activeBonus) {
            this->activeBonus = bonus;
            bonus->removeFromRoad();
        }
    }
}

std::shared_ptr<Turbohiker::Entity> Turbohiker::EntityFactory::createEntity(int lane, int position) {
    return std::make_shared<Turbohiker::Entity>(lane, position);
}

void Turbohiker::Entity::removePassiveBonus() {
    if (passiveBonus->getType() == Turbohiker::speed) {
        this->maxSpeed = 2;
        if (this->speed == 3) {
            this->speed = 2;
        }
        this->passiveBonus = nullptr;
    }
}

void Turbohiker::Entity::addMinusPoint() {
    this->minusPoints++;
}

int Turbohiker::Entity::getMinusPoints() {
    return this->minusPoints;
}