
#ifndef TURBOPLAYER
#define TURBOPLAYER

#include "Entity.h"
#include "Bonus.h"

namespace Turbohiker {
    class Player: public Entity {

    public:
        Player(int lane = 0) : Entity(lane) {}
    };
}

#endif