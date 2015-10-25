//
//  Tools.h
//  PlantsVSZombies
//
//  Created by user on 13-6-13.
//
//

#ifndef __PlantsVSZombies__Tools__
#define __PlantsVSZombies__Tools__



#include <iostream>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
class Tools
{
public:
    static Point getCenterPoint(Point p);
    static bool iscollision(Sprite *sprite1,Sprite *sprite2);
};
#endif /* defined(__PlantsVSZombies__Tools__) */
