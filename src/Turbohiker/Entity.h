#include "Util.h"


#ifndef TURBOENTITY
#define TURBOENTITY

namespace Turbohiker {
    class Entity {
        Position position;
        unsigned int speed;
    public:
        unsigned int getSpeed();
        Position getPosition();
        void setPosition(int x, int y);
        bool changeLane(Direction direction);
        void increaseSpeed();
        void decreaseSpeed();
        void setSpeed(unsigned speed);
        Entity(int lane = 0);
    };

}

#endif