#ifndef TURBOWORLD
#define TURBOWORLD

#include <iostream>
#include "EnemyHiker.h"
#include "Bonus.h"

namespace Turbohiker {
    class World {
        std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> staticHikers;    //static
        std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> movingHikers;    //moves to you
        std::vector<std::shared_ptr<Turbohiker::Bonus>> bonuses;
        void initWorld();

    public:
        World();
        std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> getStaticHikers();
        std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> getMovingHikers();
        std::vector<std::shared_ptr<Turbohiker::EnemyHiker>> getEnemyHikers();
        std::vector<std::shared_ptr<Turbohiker::Bonus>> getBonuses();
        void addEnemy(std::shared_ptr<EnemyHiker> enemy);
    };

    class WorldFactory {
        public:
            std::unique_ptr<Turbohiker::World> createWorld();
    };
}

#endif




