#include "Racinghiker.h"

void Turbohiker::RacingHiker::advance() {
    this->setPosition(this->getPosition().x, this->getPosition().y + this->getSpeed());
}


