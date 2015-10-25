//
//  Zoombie.cpp
//  zoom
//
//  Created by student on 15/8/10.
//
//

#include "Zoombie.h"
void Zoombie::loadSpriteFrameFile(){
    log("zon");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Zombie_default.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("BucketheadZombie_default.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ConeheadZombie_default.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("FlagZombie_default.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("PoleVaultingZombie_default.plist");

}
Zoombie::Zoombie(ZoombieType zoombieType){
    this->loadSpriteFrameFile();
    switch (zoombieType) {
        case 0:
//            this->zoombieType=zoombieType;
            //这个重新创建一个精灵
//            this->createWithSpriteFrameName("Zombie1.png");
//            this->setScale(0.5);
//            sprintf(plistStr, "Zombie");
//            log("0");
            this->zoombieType=zoombieType;
            //这个只是初始化
            this->initWithSpriteFrameName("Zombie1.png");
            this->setScale(0.5);
            this->setAnchorPoint(Vec2(0.6,0.6));
            this->blood=1*LiFEVALUE;
            sprintf(plistStr, "Zombie");
            break;
        case 1:
            this->zoombieType=zoombieType;
            this->initWithSpriteFrameName("BucketheadZombie1.png");
            this->setScale(0.5);
            this->setAnchorPoint(Vec2(0.6,0.6));
            this->blood=1.5*LiFEVALUE;
            sprintf(plistStr, "BucketheadZombie");
            break;
        case 2:
            this->zoombieType=zoombieType;
            this->initWithSpriteFrameName("ConeheadZombie1.png");
            this->setScale(0.5);
            this->setAnchorPoint(Vec2(0.6,0.6));
            this->blood=LiFEVALUE;
            sprintf(plistStr, "ConeheadZombie");
            break;
        case 3:
            this->zoombieType=zoombieType;
            this->initWithSpriteFrameName("FlagZombie1.png");
            this->setScale(0.5);
            this->setAnchorPoint(Vec2(0.6,0.6));
            this->blood=LiFEVALUE;
            sprintf(plistStr, "FlagZombie");
            break;
        case 4:
            this->zoombieType=zoombieType;
            this->initWithSpriteFrameName("PoleVaultingZombie1.png");
            this->setScale(0.5);
            this->setAnchorPoint(Vec2(0.5,0.5));
            this->blood=LiFEVALUE;
            sprintf(plistStr, "PoleVaultingZombie");
            break;
    }
    //调用僵尸移动的动作
    this->runZombieAction(plistStr);
}
void Zoombie::runZombieAction(char *plist){
    log("runZombieAction");
    char temp[50];
    char temp1[50];
    //把对应的名字的僵尸放到缓存中。
    SpriteFrameCache *cache=SpriteFrameCache::getInstance();
    sprintf(temp, "%s_default.plist",plist);
    sprintf(temp1, "%s_default.png",plist);
    cache->addSpriteFramesWithFile(temp,temp1);
    //应为plist文件中用到了字典
    __Dictionary *dic=__Dictionary::createWithContentsOfFile(temp);
    __Dictionary *dic2=(__Dictionary*)dic->objectForKey("frames");
    int num=dic2->count();
    Vector<SpriteFrame*>vect;
    for (int i=0; i<num; i++){
        std::string str=StringUtils::format("%s%d.png",plist,i+1);
        auto fame=cache->getSpriteFrameByName(str);
        vect.pushBack(fame);
    }
    auto animation=Animation::createWithSpriteFrames(vect,0.1);
    auto animate=Animate::create(animation);
    this->runAction(RepeatForever::create(animate));
}

void Zoombie::move(){
    float x=this->getPosition().x;
    float tima=x*0.1;
    auto move=MoveTo::create(tima, Vec2(0, this->getPosition().y));
    auto call=CallFunc::create(CC_CALLBACK_0(Zoombie::removeZoombie,this));
    auto cosequece=Sequence::create(move,call, NULL);
    this->runAction(cosequece);
    

}
void Zoombie::removeZoombie(){
    this->removeFromParent();
}
void Zoombie::dieZoon(){
    int type=this->zoombieType;
    this->stopAllActions();
    switch (type) {
        case 0:
        case 1:
        case 2:
            sprintf(dieStr, "ZombieDie");
            break;
        case 3:
            sprintf(dieStr, "FlagZombieLostHead");
            break;
        case 4:
            sprintf(dieStr, "PoleVaultingZombieDie");
            break;
        default:
            break;
    }
    
    char temp[50];
    char temp1[50];
    sprintf(temp, "%s_default.plist",dieStr);
    sprintf(temp1, "%s_default.png",dieStr);
    SpriteFrameCache *cache=SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(temp,temp1);
    __Dictionary *dic=__Dictionary::createWithContentsOfFile(temp);
    __Dictionary *dic1=(__Dictionary*)dic->objectForKey("frames");
    int num=dic1->count();
    Vector<SpriteFrame*>vec;
    for (int i=1; i<=num; i++) {
        std::string str2=StringUtils::format("%s%i.png",dieStr,i);
        auto frame=cache->getSpriteFrameByName(str2);
        vec.pushBack(frame);
    }
    auto animation=Animation::createWithSpriteFrames(vec,0.1);
    auto animate=Animate::create(animation);
    CallFunc *call=CallFunc::create(CC_CALLBACK_0(Zoombie::removeZoombie, this));
    auto sequence=Sequence::create(animate,call, NULL);
    this->runAction(sequence);

}
void Zoombie::runBoomDie(){

    this->stopAllActions();
    char temp[50];
    sprintf(temp, "BoomDie_default.plist");
    SpriteFrameCache *cache=SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(temp);
    
    __Dictionary *dic=__Dictionary::createWithContentsOfFile(temp);
    __Dictionary *dic1=(__Dictionary*)dic->objectForKey("frames");
    int  num=dic1->count();
    Vector<SpriteFrame*>vec;
    for (int i=1; i<=num; i++) {
        char str[50];
        sprintf(str,"BoomDie%d.png",i);
        auto frame=cache->getSpriteFrameByName(str);
        vec.pushBack(frame);
    }
    auto animation=Animation::createWithSpriteFrames(vec,0.1);
    auto animate=Animate::create(animation);
    
    
    
    CallFunc *call=CallFunc::create(CC_CALLBACK_0(Zoombie::removeZoombie, this));
    auto sequence=Sequence::create(animate,call, NULL);
    this->runAction(sequence);
}


