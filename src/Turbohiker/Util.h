#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <random>

#ifndef TURBOUTIL
#define TURBOUTIL

namespace Turbohiker {
    enum Direction {LEFT, RIGHT};

    struct Position {
        int x;
        int y;
        Position(int x = 0, int y = 0): x(x), y(y) {}
        bool operator==(const Position& position);
    };


    class RandomSingleton {
    private:
        static RandomSingleton* instance;
        RandomSingleton();

    public:
        static RandomSingleton* getInstance();
        double random(int min, int max);
        int getRandomLane();
        int getRandomPosition(int min, int max);
    };

    bool betweenRange(Turbohiker::Position OLD, Turbohiker::Position TOCHECK, Turbohiker::Position NEW);
}




#endif