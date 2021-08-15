#ifndef BACKGROUNDREP
#define BACKGROUNDREP

#include "entityRep.h"


class BackgroundRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite() override;
    void update(unsigned int playerSpeed);
    BackgroundRep();
};

#endif