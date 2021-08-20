#include "Player.h"


std::shared_ptr<Turbohiker::Entity> Turbohiker::PlayerFactory::createEntity(int lane, int position) {
    return std::make_shared<Turbohiker::Player>(lane);
}