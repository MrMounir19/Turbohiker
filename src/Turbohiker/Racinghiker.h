#include "Entity.h"


#ifndef TURBORACINGHIKER
#define TURBORACINGHIKER

namespace Turbohiker {

    class RacingHiker: public Entity {
    public:
        RacingHiker(int lane = 0) : Entity(lane) {}
        void advance();
    };

}

#endif