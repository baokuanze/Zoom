//
//  Bullet.h
//  zoom
//
//  Created by student on 15/8/11.
//
//

#ifndef __zoom__Bullet__
#define __zoom__Bullet__

#include <stdio.h>
#include<iostream>
#include"Plants.h"
#include "Game.h"
USING_NS_CC;


class Bullet:public Sprite{
public:
    Bullet(Plants *plants ,Point point ,Layer *layout);
    void createSunflashBullet(Point p,Layer *layer);
    void removeBullet(Node *node);
    void creatPeaBullet(Point p,Layer *layer);

};
#endif /* defined(__zoom__Bullet__) */