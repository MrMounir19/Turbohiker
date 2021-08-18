#ifndef TURBOWORLD
#define TURBOWORLD
#include <iostream>
#include "EnemyHiker.h"

namespace Turbohiker {
    class World {
        std::vector<EnemyHiker*> staticHikers;    //static
        std::vector<EnemyHiker*> movingHikers;    //moves to you
        void initEnemyHikers();

    public:
        World();
        std::vector<EnemyHiker*> getStaticHikers();
        std::vector<EnemyHiker*> getMovingHikers();
        std::vector<EnemyHiker*> getEnemyHikers();
    };
}

#endif




