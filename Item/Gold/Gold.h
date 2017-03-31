#ifndef Gold_hpp
#define Gold_hpp

#include "Item.h"

class Gold : public Item{
    int amount;
    int count;
protected:
    bool isGuarded;
public:
    Gold(int amount, int count);
    int getGold();
    ObstacleType getObsType() override;
};

#endif 
