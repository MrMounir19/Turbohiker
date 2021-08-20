
#ifndef TURBOBONUS
#define TURBOBONUS

#include "Util.h"


namespace Turbohiker {
    enum BonusType {speed, spawn};
    class Bonus {
        Position position;
        BonusType type;
        int duration;
        bool activated;
        public:
            Bonus(int lane, int position, int duration = 0, Turbohiker::BonusType type = Turbohiker::spawn); // DURATION IN SEC
            BonusType getType();
            void activate();
            bool isActivated();
            void setDuration(int duration);
            int getDuration();
            void setType(Turbohiker::BonusType type);
            void reduceDuration();
            void removeFromRoad();
            Position getPosition();
    };

    class BonusFactory {
        public:
            std::shared_ptr<Turbohiker::Bonus> createBonus(int lane, int position, int duration, Turbohiker::BonusType type);
    };
}

#endif