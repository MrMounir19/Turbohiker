#include "AbstractFactory.h"

std::shared_ptr<Turbohiker::Entity> Turbohiker::EntityFactory::createEntity(int lane = 0, int position = 0) {
    return std::make_shared<Turbohiker::Entity>(lane, position);
}

std::shared_ptr<Turbohiker::Entity> Turbohiker::PlayerFactory::createEntity(int lane = 0, int position = 0) {
    return std::make_shared<Turbohiker::Player>(lane, position);
}

std::shared_ptr<Turbohiker::Entity> Turbohiker::RacinghikerFactory::createEntity(int lane = 0, int position = 0) {
    return std::make_shared<Turbohiker::RacingHiker>(lane, position);
}

std::shared_ptr<Turbohiker::Entity> Turbohiker::EnemyHikerFactory::createEntity(int lane = 0, int position = 0) {
    return std::make_shared<Turbohiker::EnemyHiker>(lane, position);
}

std::shared_ptr<Turbohiker::Entity> Turbohiker::BonusFactory::createEntity(int lane = 0, int position = 0) {
    return std::make_shared<Turbohiker::Bonus>(lane, position);
}

std::unique_ptr<Turbohiker::Game> Turbohiker::GameFactory::createGame() {
    return std::make_unique<Turbohiker::Game>();
}

std::unique_ptr<Turbohiker::World> Turbohiker::WorldFactory::createWorld() {
    return std::make_unique<Turbohiker::World>();
}