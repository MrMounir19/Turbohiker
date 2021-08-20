#ifndef TURBORACINGHIKER
#define TURBORACINGHIKER

#include "Entity.h"

namespace Turbohiker {

    class RacingHiker: public Entity {
    public:
        RacingHiker(int lane = 0) : Entity(lane) {}
    };

    class RacinghikerFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0) override;
    };
}

#endif