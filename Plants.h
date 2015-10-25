//
//  Plants.h
//  zoom
//
//  Created by student on 15/8/7.
//
//

#ifndef __zoom__Plants__
#define __zoom__Plants__

#include <iostream>
USING_NS_CC;


typedef enum {
    Sunflower = 0,//向日葵
    SmallPea,//小豌豆
    MiddlePea,//中等豌豆
    ThreeBulletPea,//三发豌豆
    Pumpkin,//南瓜
    Paprika,//辣椒
    Cherry,//樱桃
    SmallNut,//小坚果
    LargeNut,//大坚果
    Lilypad,//荷叶
    CorpseFlower,//食人花
    BombSkill
}PlantsName;

class Plants :public Sprite{
public:
    Plants(PlantsName name);
    PlantsName plantsName;
    int needSunShine;//需要的阳光值
    
    int plantInterval;//种值阳光间隔
    bool needWit ;//是否处在冷却的状态
    int tempPlanInterval;
    
    void creatPlantsByName(char *name);
    void runOneceAction(Vector<SpriteFrame *>vec);
    void CherryAction();
    void removePlants();
};
#endif
