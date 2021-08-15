#ifndef RACINGHIKERREP
#define RACINGHIKERREP

#include "entityRep.h"
#include "Turbohiker/Entity.h"

class RacingHikerRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite() override;
    RacingHikerRep();
    void update(Turbohiker::Position position, Turbohiker::Position playerPosition);
};

#endif