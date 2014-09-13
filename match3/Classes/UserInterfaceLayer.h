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

//using namespace cocos2d::ui;
USING_NS_CC;

class Inventory;

class UserInterfaceLayer : public cocos2d::Layer
{
    //void touchEvent(Button *pSender, TouchEventType type);
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(UserInterfaceLayer);
    
    //CC_SYNTHESIZE_READONLY(Inventory *, _inventory, Inventory);
};

#endif /* defined(__QuestGame__UserInterfaceLayer__) */
