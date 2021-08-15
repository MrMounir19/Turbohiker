#include "Util.h"

bool Turbohiker::Position::operator==(const Position& position) {
    return this->x == position.x && this->y == position.y;
}
