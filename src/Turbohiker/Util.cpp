#include "Util.h"

bool Turbohiker::Position::operator==(const Position& position) {
    return this->x == position.x && abs(this->y - position.y) < 10;
}

bool Turbohiker::betweenRange(Turbohiker::Position OLD, Turbohiker::Position TOCHECK, Turbohiker::Position NEW) {
    if (OLD.y == NEW.y) {
        return OLD.y-10 <= TOCHECK.y and NEW.y+10 >= TOCHECK.y;
    }
    return OLD.y <= TOCHECK.y and NEW.y+10 >= TOCHECK.y;
}
