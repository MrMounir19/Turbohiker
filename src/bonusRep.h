#ifndef BONUSREP
#define BONUSREP

#include "entityRep.h"
#include "Turbohiker/Bonus.h"

class BonusRep: public EntityRep {
    Turbohiker::BonusType type;
public:
    void initTexture() override;
    void initSprite() override;
    void update(Turbohiker::Position position, Turbohiker::Position playerPosition);
    BonusRep(Turbohiker::BonusType type);
};

#endif