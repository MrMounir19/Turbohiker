#include "Player.h"
#include "Racinghiker.h"
#include "World.h"


#ifndef TURBOGAME
#define TURBOGAME

namespace Turbohiker {    
    class Game {
        Player* player;
        std::vector<RacingHiker*> AI;
        World* world;
        void initPlayer();
        void initAI();
        void initWorld();
    public:
        Game();
        ~Game();
        Player* getPlayer();
        void update();
        std::vector<RacingHiker*> getAI();
        bool findCollision();
        bool checkCollision(Entity* hiker);
        bool changeLane(Turbohiker::Direction direction, Turbohiker::Entity* hiker);
    };
}

#endif