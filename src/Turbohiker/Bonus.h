
#ifndef BONUS
#define BONUS

#include "Entity.h"

namespace Turbohiker {
    enum BonusType {speed, spawn};
    class Bonus: public Entity {
        BonusType type;
        int duration;
        bool activated;
        public:
            Bonus(int lane, int position, int duration, Turbohiker::BonusType type); // DURATION IN SEC
            BonusType getType();
            int getDuration();
    };
}

#endif