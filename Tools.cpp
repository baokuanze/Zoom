//
//  Tools.cpp
//  PlantsVSZombies
//
//  Created by user on 13-6-13.
//
//

#include "Tools.h"
CCPoint Tools::getCenterPoint(CCPoint p)
{
    CCPoint point;
    if(p.y<66)
        point.y=40;
    else if(p.y<118)
        point.y=95;
    else if(p.y<170)
        point.y=150;
    else if(p.y<222)
        point.y=205;
    else point.y=260;
    
    if(p.x<104)
        point.x=76;
    else if(p.x<142)
        point.x=123;
    else if(p.x<190)
        point.x=165;
    else if(p.x<230)
        point.x=209;
    else if(p.x<276)
        point.x=250;
    else if(p.x<315)
        point.x=293;
    else if(p.x<362)
        point.x=339;
    else if(p.x<402)
        point.x=380;
    else if(p.x<452)
        point.x=428;
    return point;
}

bool Tools::iscollision(Sprite *sprite1,Sprite *sprite2)
{
    Rect rect1 = sprite1->boundingBox();
    Rect rect2 = sprite2->boundingBox();
    float rect1MinX = rect1.getMinX();
    float rect1MaxX = rect1.getMaxX();
    float rect1MinY = rect1.getMinY();
    float rect1MaxY = rect1.getMaxY();
    
    float rect2MinX = rect2.getMinX()+50;
    float rect2MaxX = rect2.getMaxX();
    float rect2MinY = rect2.getMinY();
    float rect2MaxY = rect2.getMaxY();
    
    if ( rect1MinX>rect2MaxX ||rect1MinY>rect2MaxY)
        return false;
    if ( rect2MinX>rect1MaxX ||rect2MinY>rect1MaxY )
        return false;
    return true;
     
}