#ifndef GridObjects_hpp
#define GridObjects_hpp

#include "Floor.h"
#include "ObstacleType.h"


class GridObjects : public Floor{
    int previousRow;
    int previousCol;
    int currentRow;
    int currentCol;
    virtual ObstacleType getObsType() = 0;
};

#endif
