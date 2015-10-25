//
//  Bullet.cpp
//  zoom
//
//  Created by student on 15/8/11.
//
//
#include "Bullet.h"
Bullet::Bullet(Plants *plants ,Point point ,Layer *layout){
    plants=new Plants(plants->plantsName);
    switch (plants->plantsName) {
        case Sunflower:
            log("aaa");
            createSunflashBullet(point, layout);
            break;
        case SmallPea:
        case MiddlePea:
        case ThreeBulletPea:
        {
            this->creatPeaBullet(point, layout);
            break;
        }
        default:
            break;
    }
}
//阳关
void Bullet::createSunflashBullet(Point p, Layer *layer){
    auto cache=SpriteFrameCache::getInstance();
    char temp[50]="Sun_default.plist";
    cache->addSpriteFramesWithFile("Sun_default.plist", "Sun_default.png");
    this->initWithSpriteFrameName("Sun－1（被拖移）.tiff");
    this->setScale(0.4);
    __Dictionary *dic=__Dictionary::createWithContentsOfFile(temp);
    __Dictionary *dic2=(__Dictionary*)dic->objectForKey("frames");
    int num=(int)dic2->allKeys()->count();
    Vector<SpriteFrame *>vect;
    for ( int i=1; i<=num; i++) {
        std:: string str=StringUtils::format("Sun－%d（被拖移）.tiff",i);
        auto frame=cache->getSpriteFrameByName(str);
        vect.pushBack(frame);
    }
    auto animation=Animation::createWithSpriteFrames(vect,0.1);
    auto animate=Animate::create(animation);
    this->runAction(RepeatForever::create(animate));

    auto spriteItem=MenuItemSprite::create(this,this,[layer](Ref *sender){
        auto sprite=static_cast<MenuItemSprite*>(sender);
        auto move=MoveTo::create(1, Vec2(55, 320));
        
        auto call=CallFuncN::create([layer](Node *sen){
            sen->removeFromParent();
            //移除之后将获得lable的值进行相加+50
            auto laye=(GameScene *)layer;
            auto lable=laye->lable;
            int a= atoi( lable->getString().c_str())+50;
            std::string str=StringUtils::format("%d",a);
            lable->setString(str);
        });
        
        auto sequence=Sequence::create(move,call, NULL);
        auto menu= sprite->getParent();
        menu->runAction(sequence);
    });
    
    auto menu=Menu::create(spriteItem, NULL);
    menu->setPosition(p.x+20,p.y+25);
    layer->addChild(menu);
    auto jump=JumpTo::create(1, Vec2(p.x-5,p.y-5), 30, 1);
    menu->runAction(jump);
}


void Bullet::removeBullet(Node *node){
    auto bullet=static_cast<Sprite*>(node);
    bullet->removeFromParent();
}
//子弹
void Bullet::creatPeaBullet(Point p,Layer *layer){
    log("dddd");
    auto cache=SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("PeashooterBullet_default.plist");
    this->initWithSpriteFrameName("PeashooterBullet－1（被拖移）.tiff");
    this->setPosition(p.x+10,p.y+10);
    this->setScale(0.5);
    layer->addChild(this);
    float distance=500-this->getPosition().x;
    float time=distance/200;
    auto call=CallFuncN::create(CC_CALLBACK_1(Bullet::removeBullet, this));
    auto moveto=MoveTo::create(time, Vec2(500, this->getPosition().y));
    auto sequence=Sequence::create(moveto,call, NULL);
    this->runAction(sequence);
}




