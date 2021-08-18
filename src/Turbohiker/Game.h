#include "Player.h"
#include "World.h"
#include "Racinghiker.h"


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
        World* getWorld();
        void update();
        void updateEntity(Entity* entity);
        void removeUpdates();
        void yell(Entity* hiker);
        EnemyHiker* closestEnemy(Entity* hiker);
        std::vector<RacingHiker*> getAI();
        bool findCollision();
        bool checkCollision(Entity* hiker, Turbohiker::Position oldPosition);
        bool changeLane(Turbohiker::Direction direction, Turbohiker::Entity* hiker);
    };
}

#endif