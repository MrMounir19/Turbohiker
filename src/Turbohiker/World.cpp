#include "World.h"


Turbohiker::World::World() {
    this->initEnemyHikers();
}

void Turbohiker::World::initEnemyHikers() {
    Turbohiker::RandomSingleton* X = Turbohiker::RandomSingleton::getInstance();
    int amountEnemies = 10;
    int amountBonuses = 6; //3 speed, 3 spawn
    srand(time(NULL));
    
    //GENERATE ENEMIES
    for (int i = 0; i < amountEnemies/2; i++) {
        int lane = X->getRandomLane();
        int position = X->getRandomPosition(1000, 7200);
        this->staticHikers.push_back(new EnemyHiker(lane, position));
        lane = X->getRandomLane();
        position = X->getRandomPosition(1000, 7200);
        this->movingHikers.push_back(new EnemyHiker(lane, position, -4));
    }

    //GENERATE BONUSES
    for (int i = 0; i < amountBonuses/2; i++) {
        int lane = X->getRandomLane();
        int position = X->getRandomPosition(1000, 7200);
        this->bonuses.push_back(new Bonus(lane, position, 5, Turbohiker::speed));
        lane = X->getRandomLane();
        position = X->getRandomPosition(1000, 7200);
        this->bonuses.push_back(new Bonus(lane, position, 0, Turbohiker::spawn));
    }
}

std::vector<Turbohiker::EnemyHiker*> Turbohiker::World::getStaticHikers() {
    return this->staticHikers;
}

std::vector<Turbohiker::EnemyHiker*> Turbohiker::World::getMovingHikers() {
    return this->movingHikers;
}

std::vector<Turbohiker::EnemyHiker*> Turbohiker::World::getEnemyHikers() {
    std::vector<Turbohiker::EnemyHiker*> temp = this->staticHikers;
    temp.insert(temp.end(), this->movingHikers.begin(), this->movingHikers.end());
    return temp;
}

std::vector<Turbohiker::Bonus*> Turbohiker::World::getBonuses() {
    return this->bonuses;
}