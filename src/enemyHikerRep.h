#ifndef STSA
#define STA

#include "entityRep.h"
#include "Turbohiker/Entity.h"
#include "Turbohiker/EnemyHiker.h"

class EnemyHikerRep: public EntityRep {
    
public:
    void initTexture() override;
    void initSprite() override;
    EnemyHikerRep();
    void update(std::shared_ptr<Turbohiker::EnemyHiker> hiker, Turbohiker::Position playerPosition);
};

#endif