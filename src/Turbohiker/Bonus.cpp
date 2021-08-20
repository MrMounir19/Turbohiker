#include "Bonus.h"

Turbohiker::BonusType Turbohiker::Bonus::getType() {
    return this->type;
}

int Turbohiker::Bonus::getDuration() {
    return this->duration;
}

Turbohiker::Bonus::Bonus(int lane, int position, int duration, Turbohiker::BonusType type) {
    this->position.x = lane;
    this->position.y = position;
    this->duration = duration*60;
    this->type = type;
    this->activated = false;
}

void Turbohiker::Bonus::activate() {
    this->activated = true;
}

bool Turbohiker::Bonus::isActivated() {
    return this->activated;
}

void Turbohiker::Bonus::setDuration(int duration) {
    this->duration = duration*60;
}
void Turbohiker::Bonus::setType(Turbohiker::BonusType type) {
    this->type = type;
}

std::shared_ptr<Turbohiker::Bonus> Turbohiker::BonusFactory::createBonus(int lane, int position, int duration, Turbohiker::BonusType type) {
    return std::make_shared<Turbohiker::Bonus>(lane, position, duration, type);
}

Turbohiker::Position Turbohiker::Bonus::getPosition() {
    return this->position;
}

void Turbohiker::Bonus::reduceDuration() {
    this->duration--;
}

void Turbohiker::Bonus::removeFromRoad() {
    this->position.x = 99999999;
    this->position.y = 99999999;
}