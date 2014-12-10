//
//  UserInterfaceLayer.h
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#ifndef __QuestGame__UserInterfaceLayer__
#define __QuestGame__UserInterfaceLayer__

#include "cocos2d.h"
//#include "CocosGUI.h"
#include "Hero.h"
#include "Enemy.h"
//using namespace cocos2d::ui;
USING_NS_CC;

class Inventory;

class UserInterfaceLayer : public cocos2d::Layer
{
    Label *labelHeroHealth;
    Label *labelHeroDamage;
    Label *labelHeroRage;
    //void touchEvent(Button *pSender, TouchEventType type);
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(UserInterfaceLayer);
    
    void updateInterface();
};

#endif /* defined(__QuestGame__UserInterfaceLayer__) */
