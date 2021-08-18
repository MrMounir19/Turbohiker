#include "Util.h"


#ifndef TURBOENTITY
#define TURBOENTITY

namespace Turbohiker {
    class Entity {
        Position position;
        unsigned int speed;
        bool updated;
    public:
        //UPDATE
        bool getUpdated();
        void setUpdated(bool update);
        virtual void update();

        //POSITION
        Position getPosition();
        void setPosition(int x, int y);
        bool changeLane(Direction direction);
        
        //SPEED
        void increaseSpeed();
        void decreaseSpeed();
        unsigned int getSpeed();
        void setSpeed(unsigned speed);
        
        //CONSTRUCTOR
        Entity(int lane = 0, int position = 0);
    };

}

#endif