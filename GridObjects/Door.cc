//
//  Door.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "Door.h"


ObstacleType Door::getObsType(){
    return ObstacleType::BlockEnemy;
}

GridObjectType Door::getObjType(){
    return GridObjectType::Door;
}

