#ifndef RACINGHIKERREP
#define RACINGHIKERREP

#include "entityRep.h"
#include "Turbohiker/Entity.h"

class RacingHikerRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite(std::tuple<float,float> resRatio) override;
    RacingHikerRep(std::tuple<float,float> resRatio);
    void update(Turbohiker::Position position, Turbohiker::Position playerPosition, std::tuple<float,float> resRatio);
};

class RacinHikerRepFactory: public EntityRepFactory {
    public:
        std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};

#endif