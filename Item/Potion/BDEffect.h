#ifndef BDEffect_hpp
#define BDEffect_hpp

#include "PotionEffect.h"

class BDEffect : public PotionEffect{
public:
    BDEffect(shared_ptr<Player> pc);
    double getDefence() override;
};

#endif
