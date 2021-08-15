#include "Player.h"

void Turbohiker::Player::advance() {
    this->setPosition(this->getPosition().x, this->getPosition().y+getSpeed());
}
