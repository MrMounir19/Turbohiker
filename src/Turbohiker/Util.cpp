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


Turbohiker::RandomSingleton* Turbohiker::RandomSingleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Turbohiker::RandomSingleton();
    }

    return instance;
}

Turbohiker::RandomSingleton::RandomSingleton() {}


double Turbohiker::RandomSingleton::random(int min, int max) {
    std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

int Turbohiker::RandomSingleton::getRandomLane() {
    //srand(time(NULL));
    return rand() % 4;
}

int Turbohiker::RandomSingleton::getRandomPosition(int min, int max) {
    //srand(time(NULL));
    return min + (rand() % (max - min));

}

Turbohiker::RandomSingleton* Turbohiker::RandomSingleton::instance = 0;
