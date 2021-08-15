#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "menu.h"
#include "Turbohiker/Game.h"
#include "backgroundRep.h"
#include "playerRep.h"
#include "racingHikerRep.h"
#include "entityRep.h"

class Game {
    // VARIABLES
    PlayerRep* playerRep;
    std::vector<RacingHikerRep*> racingHikerReps;
    BackgroundRep* backgroundRep;
    Menu* menu;
    Turbohiker::Game* turboGame;
    sf::RenderWindow* window;
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