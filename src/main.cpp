#include <SFML/Graphics.hpp>
#include "game.h"


int main()
{
    //INIT GAME

    Game game;

    while (game.running())
    {   
        game.run();
    }

    return 0;
}
