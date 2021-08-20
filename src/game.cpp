#include "game.h"
#include <iostream>

void Game::initWindow() {
    this->videoMode.width = sf::VideoMode::getDesktopMode().width;
    this->videoMode.height = sf::VideoMode::getDesktopMode().height;
    this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "Turbohiker");
    this->resRatio = std::make_tuple(((int)this->videoMode.width) /1920.f, ((int)this->videoMode.height)/1080.f);
    this->window->setFramerateLimit(60);
}

void Game::initTurboGame() {
    std::unique_ptr<Turbohiker::GameFactory> gameFactory = std::make_unique<Turbohiker::GameFactory>();
    this->turboGame = gameFactory->createGame();
}

void Game::initMenu() {
    std::unique_ptr<MenuFactory> menuFactory = std::make_unique<MenuFactory>();
    this->menu = menuFactory->createMenu(window->getSize().x, window->getSize().y);
}

void Game::initReps() {
    //empty vectors
    for (auto& racingHikerRep:racingHikerReps) {
        racingHikerReps.pop_back();
    }

    for (auto& enemyHikerRep:enemyHikerReps) {
        enemyHikerReps.pop_back();
    }

    for (auto& bonus:bonusReps) {
        bonusReps.pop_back();
    }

    //PLAYER
    std::unique_ptr<PlayerRepFactory> playerRepFactory = std::make_unique<PlayerRepFactory>();
    this->playerRep = std::dynamic_pointer_cast<PlayerRep>(playerRepFactory->createEntityRep(resRatio));

    //ROAD
    std::unique_ptr<BackgroundRepFactory> backgroundRepFactory = std::make_unique<BackgroundRepFactory>();
    this->backgroundRep = std::dynamic_pointer_cast<BackgroundRep>(backgroundRepFactory->createEntityRep(resRatio));

    //racing
    std::unique_ptr<RacinHikerRepFactory> racingHikerRepFactory = std::make_unique<RacinHikerRepFactory>();
    for (auto& racingHiker:this->turboGame->getAI()) {
        this->racingHikerReps.push_back(std::dynamic_pointer_cast<RacingHikerRep>(racingHikerRepFactory->createEntityRep(resRatio)));
    }
    //ENEMYHIKERS
    std::unique_ptr<EnemyHikerRepFactory> enemyHikerRepFactory = std::make_unique<EnemyHikerRepFactory>();
    for (auto& enemyhiker:this->turboGame->getWorld()->getEnemyHikers()) {
        this->enemyHikerReps.push_back(std::dynamic_pointer_cast<EnemyHikerRep>(enemyHikerRepFactory->createEntityRep(resRatio)));
    }

    //BONUS
    std::unique_ptr<BonusRepFactory> bonusRepFactory = std::make_unique<BonusRepFactory>();
    for (auto& bonus:this->turboGame->getWorld()->getBonuses()) {
        this->bonusReps.push_back(std::make_unique<BonusRep>(bonus->getType(), resRatio));
    }

    //FINISH LINE
    std::unique_ptr<FinishLineRepFactory> finishLineRepFactory = std::make_unique<FinishLineRepFactory>();
    this->finishLineRep = std::dynamic_pointer_cast<FinishLineRep>(finishLineRepFactory->createEntityRep(resRatio));
}

Game::~Game() {

}

Game::Game() {
    this->initTurboGame();
    this->initWindow();
    this->initReps();
    this->initMenu();
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::update() {
    this->pollEvents();
    if (!this->menu->isActivated()) {
        if (this->turboGame->isRunning()) {
            this->turboGame->update();
            
            if (this->turboGame->getPlayer()->getSpeed() != 0) {
                this->playerRep->update(this->turboGame->getPlayer()->getPosition(), resRatio);
            }

            //ADD NEW SPAWNED AI
            if (enemyHikerReps.size() != this->turboGame->getWorld()->getEnemyHikers().size()) {
                std::unique_ptr<EnemyHikerRepFactory> enemyHikerRepFactory = std::make_unique<EnemyHikerRepFactory>();
                for (int i = enemyHikerReps.size(); i < this->turboGame->getWorld()->getEnemyHikers().size(); i++) {
                    this->enemyHikerReps.push_back(std::dynamic_pointer_cast<EnemyHikerRep>(enemyHikerRepFactory->createEntityRep(resRatio)));
                }
            }

            //FINISH LINE
            this->finishLineRep->update(this->turboGame->getPlayer()->getPosition(), resRatio);

            //AI
            for (unsigned int i = 0; i < this->turboGame->getAI().size(); i++) {
                Turbohiker::Position position = this->turboGame->getAI()[i]->getPosition();
                if (this->turboGame->getAI()[i]->getSpeed() != 0) {
                    this->racingHikerReps[i]->update(position, this->turboGame->getPlayer()->getPosition(), resRatio);
                }
            }
            //ENEMIES
            for (unsigned int i = 0; i < this->turboGame->getWorld()->getEnemyHikers().size(); i++) {
                std::shared_ptr<Turbohiker::EnemyHiker> enemyhiker = this->turboGame->getWorld()->getEnemyHikers()[i];
                Turbohiker::Position position = enemyhiker->getPosition();
                this->enemyHikerReps[i]->update(enemyhiker, this->turboGame->getPlayer()->getPosition(), resRatio);
            }
            //BONUSES
            for (unsigned int i = 0; i < this->turboGame->getWorld()->getBonuses().size(); i++) {
                std::shared_ptr<Turbohiker::Bonus> bonus = this->turboGame->getWorld()->getBonuses()[i];
                Turbohiker::Position position = bonus->getPosition();
                this->bonusReps[i]->update(position, this->turboGame->getPlayer()->getPosition(), resRatio);
            }
            //BACKGROUND
            this->backgroundRep->update(this->turboGame->getPlayer()->getSpeed(), resRatio);
            this->turboGame->removeUpdates();
        }
        else {
            this->menu->setActivated(true);
            this->menu->setType(1);
            this->menu->setIndex(0);
            this->menu->setScores(this->turboGame->getPlayerScore(), this->turboGame->getAIScores());
        }
    }
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
                                    if (menu->getType() == 1) {
                                        //RESTART EVERYTHING
                                        this->initTurboGame();
                                        this->initReps();
                                        this->initMenu();
                                    }
                                    menu->setActivated(false);

                                    break;
                                case 1: //EXIT
                                    this->window->close();
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
                        case sf::Keyboard::Space:
                            this->turboGame->yell(this->turboGame->getPlayer());
                            break;

                        case sf::Keyboard::Enter:
                            this->turboGame->activateBonus(this->turboGame->getPlayer());
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
    //DRAW
    if (this->menu->isActivated()) {
        menu->draw(*this->window);
    }
    else {
        //RENDER ROAD
        this->backgroundRep->render(*this->window);

        //RENDER BONUS
        for (auto& bonusRep:this->bonusReps) {
            bonusRep->render(*this->window);
        }
        
        //RENDER STATIC AND RUNNING
        for (auto& enemyhikerRep:this->enemyHikerReps) {
            enemyhikerRep->render(*this->window);
        }

        //RENDER AI
        for (auto& racingHikerRep:this->racingHikerReps) {
            racingHikerRep->render(*this->window);
        }

        //RENDER PLAYER
        this->playerRep->render(*this->window);

        //FINISH LINE
        this->finishLineRep->render(*this->window);
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

