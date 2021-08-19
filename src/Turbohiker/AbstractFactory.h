


#ifndef TURBOFACTORY
#define TURBOFACTORY

#include "Player.h"
#include "World.h"
#include "Game.h"
#include "Racinghiker.h"
#include "Bonus.h"
#include "EnemyHiker.h"

namespace Turbohiker {

    class EntityFactory {
        public:
            virtual std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0);
    };

    class PlayerFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0);
    };

    class RacinghikerFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity>  createEntity(int lane = 0, int position = 0);
    };

    class EnemyHikerFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0);
    };

    class BonusFactory: public EntityFactory {
        public:
            std::shared_ptr<Turbohiker::Entity> createEntity(int lane = 0, int position = 0);
    };


    class GameFactory {
        public:
            std::unique_ptr<Turbohiker::Game> createGame();
    };

    class WorldFactory {
        public:
            std::unique_ptr<Turbohiker::World> createWorld();
    };

}

#endif