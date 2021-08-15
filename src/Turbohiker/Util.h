#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

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
}

#endif