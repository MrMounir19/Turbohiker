#include "World.h"


Turbohiker::World::World() {
    this->initEnemyHikers();
}

void Turbohiker::World::initEnemyHikers() {
    int amountEnemies = 10;
    srand(time(NULL));
    
    for (int i = 0; i < amountEnemies/2; i++) {
        int lane = rand() % 4;
        int position = (rand() % 7200) + 1000;
        this->staticHikers.push_back(new EnemyHiker(lane, position));
        lane = rand() % 4;
        position = (rand() % 7200) + 1000;
        this->movingHikers.push_back(new EnemyHiker(lane, position, -4));
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