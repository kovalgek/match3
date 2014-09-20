//
//  BackgroundLayer.cpp
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//
//#include "RootScene.h"
#include "BackgroundLayer.h"
//#include "FirstScene.h"
//#include "GameObjectsLayer.h"
//#include "Hero.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *topSprite = Sprite::create("top.png");
    topSprite->setPosition(Point(visibleSize.width/2 + origin.x,  visibleSize.height - origin.y - topSprite->getContentSize().height/2));
    this->addChild(topSprite, 0);
    
    Sprite *grid = Sprite::create("grid.png");
    grid->setPosition(Point(visibleSize.width/2 + origin.x,  origin.y + grid->getContentSize().height/2));
    this->addChild(grid, 0);
    
    /*
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this,scene,pSprite](Touch* touch, Event* event)
    {
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        
        Point locationInNode = this->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))
        {
            Hero *hero = FirstScene::getInstance()->getGameObjectsLayer()->getHero();
            hero->go(locationInNode);
            
            Size visibleSize = Director::getInstance()->getVisibleSize();
            float distance = locationInNode.getDistance(hero->getSprite()->getPosition());
            Point point = Point(visibleSize.width/2-locationInNode.x, visibleSize.height/2-locationInNode.y);
            MoveTo *moveAction = MoveTo::create(distance/150.0f,  point);
            this->runAction(moveAction);
            
            scene->getGameObjectsLayer()->runAction(MoveTo::create(distance/150.0f,  point));
            
            return true;
        }
        return false;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    */
    return true;
}

