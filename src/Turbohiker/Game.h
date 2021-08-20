


#ifndef TURBOGAME
#define TURBOGAME

#include "Player.h"
#include "Racinghiker.h"
#include "World.h"


namespace Turbohiker {    
    class Game {
        std::shared_ptr<Player> player;
        std::vector<std::shared_ptr<RacingHiker>> AI;
        std::shared_ptr<World> world;
        void initPlayer();
        void initAI();
        void initWorld();
        int playerScore;
        std::vector<int> AIScores;
        int clock;
        bool running;
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
        std::shared_ptr<Bonus> checkCollectedBonus(std::shared_ptr<Entity> hiker, Turbohiker::Position oldPosition);
        bool changeLane(Turbohiker::Direction direction, std::shared_ptr<Entity> hiker);
        void activateBonus(std::shared_ptr<Entity> hiker);
        bool isRunning();
        int getPlayerScore();
        std::vector<int> getAIScores();
    };

    class GameFactory {
        public:
            std::unique_ptr<Turbohiker::Game> createGame();
    };
}

#endif