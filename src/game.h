#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "menu.h"
#include "Turbohiker/Game.h"
#include "backgroundRep.h"
#include "playerRep.h"
#include "racingHikerRep.h"
#include "entityRep.h"
#include "enemyHikerRep.h"
#include "bonusRep.h"
#include "finishLineRep.h"

class Game {
    // VARIABLES
    std::shared_ptr<PlayerRep>  playerRep;
    std::vector<std::shared_ptr<RacingHikerRep>> racingHikerReps;
    std::vector<std::shared_ptr<EnemyHikerRep>> enemyHikerReps;
    std::vector<std::shared_ptr<BonusRep>> bonusReps;
    std::shared_ptr<BackgroundRep> backgroundRep;
    std::shared_ptr<FinishLineRep> finishLineRep;
    std::unique_ptr<Menu> menu;
    std::unique_ptr<Turbohiker::Game> turboGame;
    std::unique_ptr<sf::RenderWindow> window;
    
    std::tuple<float, float> resRatio;
    int counterBackground;
    sf::Event ev;
    sf::VideoMode videoMode;

private:
    void initWindow();
    void initTurboGame();
    void initReps();
    void initMenu();
    void pollEvents();
    void update();
    void render();
    
public:
    //FUNCTIONS
    ~Game();
    Game();
    
    void run();
    const bool running() const;
};

#endif