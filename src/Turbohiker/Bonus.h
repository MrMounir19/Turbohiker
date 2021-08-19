
#ifndef TURBOBONUS
#define TURBOBONUS

#include "Entity.h"

namespace Turbohiker {
    class Bonus: public Entity {
        BonusType type;
        int duration;
        bool activated;
        public:
            Bonus(int lane, int position, int duration, Turbohiker::BonusType type); // DURATION IN SEC
            BonusType getType();
            int getDuration();
            void activate();
            bool isActivated();
            void setDuration(int duration);
            void setType(Turbohiker::BonusType type);
    };
}

#endif