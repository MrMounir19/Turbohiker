#ifndef TURBOWORLD
#define TURBOWORLD
#include <iostream>
#include "EnemyHiker.h"
#include "Bonus.h"

namespace Turbohiker {
    class World {
        std::vector<EnemyHiker*> staticHikers;    //static
        std::vector<EnemyHiker*> movingHikers;    //moves to you
        std::vector<Bonus*> bonuses;
        void initEnemyHikers();

    public:
        World();
        std::vector<EnemyHiker*> getStaticHikers();
        std::vector<EnemyHiker*> getMovingHikers();
        std::vector<EnemyHiker*> getEnemyHikers();
        std::vector<Bonus*> getBonuses();
    };
}

#endif




