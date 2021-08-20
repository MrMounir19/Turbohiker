#include "World.h"


Turbohiker::World::World() {
    this->initWorld();
}

void Turbohiker::World::initWorld() {
    Turbohiker::RandomSingleton* X = Turbohiker::RandomSingleton::getInstance();
    int amountEnemies = 10;
    int amountBonuses = 10; //5 speed, 5 spawn
    srand(time(NULL));
    
    std::unique_ptr<EnemyHikerFactory> enemyHikerFactory = std::make_unique<EnemyHikerFactory>();

    //GENERATE ENEMIES
    for (int i = 0; i < amountEnemies/2; i++) {
        int lane = X->getRandomLane();
        int position = X->getRandomPosition(500, 3400);
        this->staticHikers.push_back(std::dynamic_pointer_cast<EnemyHiker>(enemyHikerFactory->createEntity(lane, position)));
        lane = X->getRandomLane();
        position = X->getRandomPosition(500, 3400);
        this->movingHikers.push_back(std::dynamic_pointer_cast<EnemyHiker>(enemyHikerFactory->createEntity(lane, position)));
        this->movingHikers[i]->setSpeed(-2);
    }

    //GENERATE BONUSES
    std::unique_ptr<BonusFactory> bonusFactory = std::make_unique<BonusFactory>();

    for (int i = 0; i < amountBonuses/2; i++) {
        int lane = X->getRandomLane();
        int position = X->getRandomPosition(500, 3400);
        this->bonuses.push_back(bonusFactory->createBonus(lane, position, 5, Turbohiker::speed));
        lane = X->getRandomLane();
        position = X->getRandomPosition(500, 3400);
        this->bonuses.push_back(bonusFactory->createBonus(lane, position, 0, Turbohiker::spawn));
    }
}

std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> Turbohiker::World::getStaticHikers() {
    return this->staticHikers;
}

std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> Turbohiker::World::getMovingHikers() {
    return this->movingHikers;
}

std::vector<std::shared_ptr<Turbohiker::EnemyHiker>>Turbohiker::World::getEnemyHikers() {
    std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> temp = this->staticHikers;
    temp.insert(temp.end(), this->movingHikers.begin(), this->movingHikers.end());
    return temp;
}

std::vector<std::shared_ptr<Turbohiker::Bonus>> Turbohiker::World::getBonuses() {
    return this->bonuses;
}

void Turbohiker::World::addEnemy(std::shared_ptr<Turbohiker::EnemyHiker> enemy) {
    if (enemy->getSpeed() == 0) {
        this->staticHikers.push_back(enemy);
    }
    else {
        this->staticHikers.push_back(enemy);
    }
}





std::unique_ptr<Turbohiker::World> Turbohiker::WorldFactory::createWorld() {
    return std::make_unique<Turbohiker::World>();
}