


#ifndef TURBORACINGHIKER
#define TURBORACINGHIKER

#include "Entity.h"

namespace Turbohiker {

    class RacingHiker: public Entity {
    public:
        RacingHiker(int lane = 0) : Entity(lane) {}
    };

}

#endif