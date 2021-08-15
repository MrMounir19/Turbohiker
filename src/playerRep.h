#ifndef PLAYERREP
#define PLAYERREP

#include "entityRep.h"
#include "Turbohiker/Player.h"

class PlayerRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite() override;
    void update(Turbohiker::Position playerPosition);
    PlayerRep();
};

#endif