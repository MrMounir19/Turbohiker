#include "Bonus.h"

Turbohiker::BonusType Turbohiker::Bonus::getType() {
    return this->type;
}

int Turbohiker::Bonus::getDuration() {
    return this->duration;
}

Turbohiker::Bonus::Bonus(int lane, int position, int duration, Turbohiker::BonusType type) : Entity(lane, position) {
    this->duration = duration*60;
    this->type = type;
    this->activated = false;
    this->setSpeed(0);
}