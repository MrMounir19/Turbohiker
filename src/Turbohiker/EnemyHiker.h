#ifndef ENEMYHIKER
#define ENEMYHIKER

#include "Entity.h"

namespace Turbohiker {

    class EnemyHiker: public Entity {
    bool activated;
    Turbohiker::Direction leavingDirection;
    public:
        EnemyHiker(int lane = 0, int position = 0, int speed = 0);
        bool isActivated();
        void activate();
        void update();
        void getYelled();
        Turbohiker::Direction getDirection();
    };

    class EnemyHikerFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0) override;
    };
}

#endif