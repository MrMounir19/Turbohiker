


#ifndef TURBOGAME
#define TURBOGAME

#include "Player.h"
#include "World.h"
#include "Racinghiker.h"
#include "AbstractFactory.h"

namespace Turbohiker {    
    class Game {
        std::shared_ptr<Player> player;
        std::vector<std::shared_ptr<RacingHiker>> AI;
        std::unique_ptr<World> world;
        void initPlayer();
        void initAI();
        void initWorld();
    public:
        Game();
        ~Game();
        std::shared_ptr<Player> getPlayer();
        std::shared_ptr<World> getWorld();
        void update();
        void updateEntity(std::shared_ptr<Entity> entity);
        void removeUpdates();
        void yell(std::shared_ptr<Entity> hiker);
        std::shared_ptr<EnemyHiker> closestEnemy(std::shared_ptr<Entity> hiker);
        std::vector<std::shared_ptr<RacingHiker>> getAI();
        bool findCollision();
        bool checkCollision(std::shared_ptr<Entity> hiker, Turbohiker::Position oldPosition);
        //Bonus* checkCollectedBonus(Entity* hiker, Turbohiker::Position oldPosition);
        bool changeLane(Turbohiker::Direction direction, std::shared_ptr<Entity> hiker);
    };
}

#endif