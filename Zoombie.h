//
//  Zoombie.h
//  zoom
//
//  Created by student on 15/8/10.
//
//

#ifndef __zoom__Zoombie__
#define __zoom__Zoombie__
#define LiFEVALUE 10;
#include <stdio.h>
#include <iostream>
USING_NS_CC;

typedef enum
{
    Zombie=0,
    BucketheadZombie,
    ConeheadZombie,
    FlagZombie,
    PoleVaultingZombie,
}ZoombieType;
class Zoombie:public Sprite{
public:
    Zoombie(ZoombieType zoombieType);
    void loadSpriteFrameFile();
    void runZombieAction(char* plist);
    ZoombieType zoombieType;
    void move();
    void removeZoombie();
    void dieZoon();
    void runBoomDie();//炸弹
    char plistStr[50];
    double blood;//血量
    char dieStr[50];//加载僵尸死亡的图片
    
    
    
};
#endif /* defined(__zoom__Zoombie__) */