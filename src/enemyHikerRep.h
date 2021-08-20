#ifndef STSA
#define STA

#include "entityRep.h"
#include "Turbohiker/Entity.h"
#include "Turbohiker/EnemyHiker.h"

class EnemyHikerRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite(std::tuple<float,float> resRatio) override;
    EnemyHikerRep(std::tuple<float,float> resRatio);
    void update(std::shared_ptr<Turbohiker::EnemyHiker> hiker, Turbohiker::Position playerPosition, std::tuple<float,float> resRatio);
};

class EnemyHikerRepFactory: public EntityRepFactory {
    public:
        std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};

#endif