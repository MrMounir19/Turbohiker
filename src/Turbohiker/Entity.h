

#ifndef TURBOENTITY
#define TURBOENTITY

#include "Util.h"

namespace Turbohiker {
    enum BonusType {speed, spawn};
    class Entity {
        Position position;
        int speed;
        bool updated;
        int maxSpeed;
        int yellCooldown; // 5 seconds

        
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
        int getSpeed();
        void setSpeed(int speed);
        void upgradeMaxSpeed();
        void resetMaxSpeed();

        int getYellCooldown();
        void resetYellCooldown();
        void decreaseYellCooldown();

        //CONSTRUCTOR
        Entity(int lane = 0, int position = 0);
    };

}

#endif