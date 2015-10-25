//
//  Plants.cpp
//  zoom
//
//  Created by student on 15/8/7.
//
//

#include "Plants.h"
Plants::Plants(PlantsName name){
    plantsName=name;
    needWit=false;
    switch (name) {
        case Sunflower:
        {
            needSunShine=50;
            plantInterval=5; //种值阳光间隔
            tempPlanInterval=5;
            char t[]="SunFlower";
          
            this->creatPlantsByName(t);
            break;
        }
        case SmallNut:{
            needSunShine = 50;
            plantInterval=5;
             tempPlanInterval=5;
            char t[]="WallNut";
            this->creatPlantsByName(t);
            break;
        }
        case MiddlePea:{
            char t[]="Repeater";
            needSunShine = 200;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case ThreeBulletPea:{
            char t[]="Threepeater";
            needSunShine = 325;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case Pumpkin:
        {
            char t[]="Squash";
            needSunShine = 50;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case Paprika:{
            char t[]="Jalapeno";
            needSunShine = 125;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case Cherry:{
            char t[]="CherryBomb";
            needSunShine = 150;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case LargeNut:{
            char t[]="TallNut";
            needSunShine = 125;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case Lilypad:{
            char t[]="LilyPad";
            needSunShine = 25;
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case CorpseFlower:{
            needSunShine = 150;
            char t[]="Chomper";
            plantInterval=5;
             tempPlanInterval=5;
            this->creatPlantsByName(t);
            break;
        }
        case SmallPea:{
            needSunShine = 100;
            plantInterval=5;
             tempPlanInterval=5;
            char t[]="Peashooter";
            this->creatPlantsByName(t);
            break;
        }
    }
      this->setScale(0.5);
}

void Plants::creatPlantsByName(char *name){
    char temp[50];
    char temp1[50];
    //把对应的名字的植物放到缓存中。
    SpriteFrameCache *cache=SpriteFrameCache::getInstance();
    sprintf(temp, "%s_default.plist",name);
    sprintf(temp1, "%s_default.png",name);
    cache->addSpriteFramesWithFile(temp,temp1);
    
    //应为plist文件中用到了字典
    __Dictionary *dic=__Dictionary::createWithContentsOfFile(temp);
    __Dictionary *dic2=(__Dictionary*)dic->objectForKey("frames");
    
    sprintf(temp, "%s－2（被拖移）.tiff",name);
    this->initWithSpriteFrameName(temp);
    log("%s",temp);
    
    int num=(int)dic2->allKeys()->count();
    Vector<SpriteFrame*>vect;
    for (int i=1; i<num+1; i++) {
        sprintf(temp, "%s－%i（被拖移）.tiff",name,i);
        auto fame=cache->getSpriteFrameByName(temp);
        vect.pushBack(fame);
    }
    
    if (strcmp(name, "Jalapeno")==0||strcmp(name, "CherryBomb")==0)
    {
        this->runOneceAction(vect);
        return;
    }
    
    Animation *animation=Animation::createWithSpriteFrames(vect,0.1);
    Animate*animate=Animate::create(animation);
    this->runAction(RepeatForever::create(animate));
    
}

void Plants::runOneceAction(Vector<SpriteFrame*>vect){
    auto animation=Animation::createWithSpriteFrames(vect,0.1f);
    auto animate=Animate::create(animation);
    auto call=CallFunc::create(CC_CALLBACK_0(Plants::CherryAction,this));
    auto sequence=Sequence::create(animate,call, NULL);
    this->runAction(sequence);

}
void Plants::removePlants(){
    this->removeFromParent();
}
void Plants:: CherryAction(){
    if (this->plantsName==Cherry) {
        this->initWithFile("Boom1.png");
        auto call=CallFunc::create(CC_CALLBACK_0(Plants::removePlants, this));
        auto  sequence=Sequence::create(DelayTime::create(2.0),call, NULL);
        this->runAction(sequence);
    }
}



