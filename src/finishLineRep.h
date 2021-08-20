#ifndef FINISHLINEREP
#define FINISHLINEREP

#include "entityRep.h"
#include "Turbohiker/Entity.h"

class FinishLineRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite(std::tuple<float,float> resRatio) override;
    void update(Turbohiker::Position playerPosition, std::tuple<float,float> resRatio);
    FinishLineRep(std::tuple<float,float> resRatio);
};

class FinishLineRepFactory: public EntityRepFactory {
    public:
        std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};

#endif