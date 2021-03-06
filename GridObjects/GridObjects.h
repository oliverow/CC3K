#ifndef GridObjects_hpp
#define GridObjects_hpp

#include "Floor.h"
#include "ObstacleType.h"
#include "GridObjectType.h"
#include "Subject.h"

class GridObjects : public Subject{
protected:
    int previousRow;
    int previousCol;
    int currentRow;
    int currentCol;
public:
    virtual ObstacleType getObsType() = 0;
    virtual GridObjectType getObjType() = 0;
    void setPos(int r, int c);
    Info getInfo() override;
};
#endif
