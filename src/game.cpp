#include "game.h"
#include <iostream>

void Game::initWindow() {
    this->videoMode.width = 1920;
    this->videoMode.height = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "Turbohiker");
    this->window->setFramerateLimit(60);
}

void Game::initTurboGame() {
    this->turboGame = new Turbohiker::Game();
}

void Game::initMenu() {
    this->menu = new Menu(window->getSize().x, window->getSize().y);
}

void Game::initReps() {
    //PLAYER
    this->playerRep = new PlayerRep();
    //ROAD
    this->backgroundRep = new BackgroundRep();
    //AI
    for (auto ai:this->turboGame->getAI()) {
        this->racingHikerReps.push_back(new RacingHikerRep);
    }
}

Game::~Game() {
    delete this->window;
    delete this->menu;
    delete this->turboGame;
}

Game::Game() {
    this->initTurboGame();
    this->initReps();
    this->initWindow();
    this->initMenu();
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::update() {
    this->pollEvents();
    this->turboGame->update();
    this->playerRep->update(this->turboGame->getPlayer()->getPosition());
    for (unsigned int i = 0; i < this->turboGame->getAI().size(); i++) {
        Turbohiker::Position position = this->turboGame->getAI()[i]->getPosition();
        this->racingHikerReps[i]->update(position, this->turboGame->getPlayer()->getPosition());
    }
    this->backgroundRep->update(this->turboGame->getPlayer()->getSpeed());
}

void Game::pollEvents() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (this->menu->isActivated()) {
            switch (event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu->MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu->MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu->GetPressedItem()) {
                                case 0: //PLAY
                                    menu->setActivated(false);
                                    break;
                                case 1: //OPTIONS
                                    break;
                                case 2: //EXIT
                                    this->window->close();
                                    break;
                                case 3: //RESUME
                                    menu->setActivated(false);
                                    break;
                                case 4: //RESTART
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        else {
            switch (event.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            menu->setActivated(true);
                            break;
                        
                        //MOVE PLAYER
                        case sf::Keyboard::Left:
                            this->turboGame->changeLane(Turbohiker::LEFT, this->turboGame->getPlayer());
                            break;
                        case sf::Keyboard::Right:
                            this->turboGame->changeLane(Turbohiker::RIGHT, this->turboGame->getPlayer());
                            break;
                        case sf::Keyboard::Up:
                            this->turboGame->getPlayer()->increaseSpeed();
                            break;
                        case sf::Keyboard::Down:
                            this->turboGame->getPlayer()->decreaseSpeed();
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }
}

void Game::render() {
    this->window->clear();  
    //Draw
    if (this->menu->isActivated()) {
        menu->draw(*this->window);
    }
    else {
        //RENDER ROAD
        this->backgroundRep->render(*this->window);

        //RENDER AI
        for (auto& racingHikerRep:this->racingHikerReps) {
            racingHikerRep->render(*this->window);
        }

        //RENDER PLAYER
        this->playerRep->render(*this->window);
    }
    //DISPLAY
    this->window->display();
}

void Game::run() {
    //UPDATE
    this->update();

    //RENDER
    this->render();
}