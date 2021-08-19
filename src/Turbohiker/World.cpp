#include "World.h"


Turbohiker::World::World() {
    this->initWorld();
}

void Turbohiker::World::initWorld() {
    Turbohiker::RandomSingleton* X = Turbohiker::RandomSingleton::getInstance();
    int amountEnemies = 10;
    int amountBonuses = 6; //3 speed, 3 spawn
    srand(time(NULL));
    
    std::unique_ptr<EnemyHikerFactory> enemyHikerFactory = std::make_unique<EnemyHikerFactory>();

    //GENERATE ENEMIES
    for (int i = 0; i < amountEnemies/2; i++) {
        int lane = X->getRandomLane();
        int position = X->getRandomPosition(1000, 7200);
        this->staticHikers.push_back(std::dynamic_pointer_cast<EnemyHiker>(enemyHikerFactory->createEntity(lane, position)));
        lane = X->getRandomLane();
        position = X->getRandomPosition(1000, 7200);
        this->movingHikers.push_back(std::dynamic_pointer_cast<EnemyHiker>(enemyHikerFactory->createEntity(lane, position)));
        this->movingHikers[i]->setSpeed(-2);
    }

    //GENERATE BONUSES
    std::unique_ptr<BonusFactory> bonusFactory = std::make_unique<BonusFactory>();

    for (int i = 0; i < amountBonuses/2; i++) {
        int lane = X->getRandomLane();
        int position = X->getRandomPosition(1000, 7200);
        this->bonuses.push_back(std::dynamic_pointer_cast<Bonus>(bonusFactory->createEntity(lane, position)));
        this->bonuses[2*i]->setDuration(5);
        this->bonuses[2*i]->setType(Turbohiker::speed);
        lane = X->getRandomLane();
        position = X->getRandomPosition(1000, 7200);
        this->bonuses.push_back(std::dynamic_pointer_cast<Bonus>(bonusFactory->createEntity(lane, position)));
        this->bonuses[2*i+1]->setDuration(0);
        this->bonuses[2*i+1]->setType(Turbohiker::spawn);
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