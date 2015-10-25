#include "HelloWorldScene.h"
#include "Game.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("main_background.png");
    //sprite->setScale(2.5);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite);
    //模式
    auto item1=MenuItemImage::create("select10.png","select11.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    //item1->setScale(2.5);
    auto item2=MenuItemImage::create("select20.png","select21.png");
    //item2->setScale(2.5);
    auto item3=MenuItemImage::create("select30.png","select31.png");
    //item3->setScale(2.5);
    auto item4=MenuItemImage::create("select40.png","select41.png");
    //item4->setScale(2.5);
    auto menu=Menu::create(item1,item2,item3,item4,nullptr);
   // menu->setPosition(900, 450);
    menu->setPosition(380, 200);
    menu->alignItemsVerticallyWithPadding(-20);
    this->addChild(menu);
    //商店
    auto item5=MenuItemImage::create("SelectorScreen_Almanac.png","SelectorScreen_AlmanacHighlight.png");
    item5->setScale(0.5);
    auto item6=MenuItemImage::create("shop0.png","shop1.png");
    item6->setScale(0.5);
    auto menu2=Menu::create(item5,item6,nullptr);
    menu2->setPosition(Vec2(300,80));
    menu2->alignItemsHorizontallyWithPadding(20);
    this->addChild(menu2);
    //成就
    auto item7=MenuItemImage::create("chengjiu1.png","chengjiu.png");
    item7->setScale(0.5);
    auto menu3=Menu::create(item7,nullptr);
    menu3->setPosition(115,80);
    this->addChild(menu3);
    
    //选项
//   auto label=Label::createWithTTF("选项","fonts/arial.ttf",130);
//   label->setPosition(500,150);
//   label->setColor(Color3B::BLUE);
//    this->addChild(label);
    //字体
    MenuItemFont *font=MenuItemFont::create("选项");
    font->setColor(Color3B::BLUE);
    font->setFontSizeObj(20);
    MenuItemFont *font1=MenuItemFont::create("帮助");
    font1->setColor(Color3B::BLUE);
    font1->setFontSizeObj(20);
    auto fontMenu=Menu::create(font,font1, NULL);
    fontMenu->setPosition(380,40);
    fontMenu->alignItemsHorizontallyWithPadding(20);
    this->addChild(fontMenu);
    
    //音乐
    auto item8=MenuItemImage::create("musicbutton2.png","musicbuttonstop2.png");
  //  item8->setScale(1.3);
    auto musicMenu=Menu::create(item8,nullptr);
    musicMenu->setPosition(1200,200);
    this->addChild(musicMenu);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    log("dddd");
    auto scene=GameScene::createScene();
      TransitionSlideInL *inr=TransitionSlideInL::create(2, scene);
    Director::getInstance()->replaceScene(inr);

    
}
