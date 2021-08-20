#ifndef BACKGROUNDREP
#define BACKGROUNDREP

#include "entityRep.h"


class BackgroundRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite(std::tuple<float,float> resRatio) override;
    void update(unsigned int playerSpeed, std::tuple<float,float> resRatio);
    BackgroundRep(std::tuple<float,float> resRatio);
};

class BackgroundRepFactory: public EntityRepFactory {
    public:
        std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};

#endif