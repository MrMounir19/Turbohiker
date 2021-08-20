#ifndef BONUSREP
#define BONUSREP

#include "entityRep.h"
#include "Turbohiker/Bonus.h"

class BonusRep: public EntityRep {
    Turbohiker::BonusType type;
public:
    void initTexture() override;
    void initSprite(std::tuple<float,float> resRatio) override;
    void update(Turbohiker::Position position, Turbohiker::Position playerPosition, std::tuple<float,float> resRatio);
    BonusRep(Turbohiker::BonusType type, std::tuple<float,float> resRatio);
};

class BonusRepFactory: public EntityRepFactory {
    public:
        std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};

#endif