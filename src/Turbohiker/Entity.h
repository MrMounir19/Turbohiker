

#ifndef TURBOENTITY
#define TURBOENTITY

#include "Util.h"
#include "Bonus.h"

namespace Turbohiker {
    
    class Entity {
        Position position;
        int speed;
        bool updated;
        int maxSpeed;
        int minusPoints;
        int yellCooldown; // 5 seconds
        std::shared_ptr<Bonus> passiveBonus;
        std::shared_ptr<Bonus> activeBonus;

    public:
        //UPDATE
        bool getUpdated();
        void setUpdated(bool update);
        virtual void update();
        void addMinusPoint();
        int getMinusPoints();
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

        //BONUS
        void setActiveBonus(std::shared_ptr<Bonus> bonus);
        void setPassiveBonus(std::shared_ptr<Bonus> bonus);
        std::shared_ptr<Bonus> getActiveBonus();
        std::shared_ptr<Bonus> getPassiveBonus();
        void applyBonus(std::shared_ptr<Bonus> bonus);
        void removePassiveBonus();


        //CONSTRUCTOR
        Entity(int lane = 0, int position = 0);
    };

    class EntityFactory {
        public:
            virtual std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0);
    };
}

#endif