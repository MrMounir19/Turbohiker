#include "Racinghiker.h"

std::shared_ptr<Turbohiker::Entity> Turbohiker::RacinghikerFactory::createEntity(int lane, int position) {
    return std::make_shared<Turbohiker::RacingHiker>(lane);
}

