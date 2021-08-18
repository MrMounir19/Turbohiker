#include "Entity.h"


#ifndef TURBOPLAYER
#define TURBOPLAYER

namespace Turbohiker {
    class Player: public Entity {
    public:
        Player(int lane = 0) : Entity(lane) {}
    };
}

#endif