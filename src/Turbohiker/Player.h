
#ifndef TURBOPLAYER
#define TURBOPLAYER

#include "Entity.h"
#include "Bonus.h"

namespace Turbohiker {
    class Player: public Entity {

    public:
        Player(int lane = 0) : Entity(lane) {}
    };

    class PlayerFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0) override;
    };
    
}

#endif