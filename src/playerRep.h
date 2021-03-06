#ifndef PLAYERREP
#define PLAYERREP

#include "entityRep.h"
#include "Turbohiker/Player.h"

class PlayerRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite(std::tuple<float,float> resRatio) override;
    void update(Turbohiker::Position playerPosition, std::tuple<float,float> resRatio);
    PlayerRep(std::tuple<float,float> resRatio);
};

class PlayerRepFactory: public EntityRepFactory {
    public:
        std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};



#endif

