//
//  UserInterfaceLayer.cpp
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#include "UserInterfaceLayer.h"
//#include "Inventory.h"

//#include "RootScene.h"

//#include "Inventory.h"
//#include "InventoryObject.h"

USING_NS_CC;

//using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool UserInterfaceLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *topSprite = Sprite::create("top.png");
    topSprite->setPosition(Point(visibleSize.width/2 + origin.x,  visibleSize.height - origin.y - topSprite->getContentSize().height/2));
    this->addChild(topSprite, 0);
    
    /*
    Layout *layout = Layout::create();
    layout->setSize(visibleSize);
    layout->setClippingEnabled(true);
    layout->setLayoutType(LAYOUT_RELATIVE);
    this->addChild(layout);
    
    Button *button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextures("inventoryIcon.png", "inventoryIcon.png", "");
    button->setScale(0.3f);
    button->addTouchEventListener(this, toucheventselector(UserInterfaceLayer::touchEvent));
    layout->addChild(button);
    
    RelativeLayoutParameter *rp1 = RelativeLayoutParameter::create();
    rp1->setMargin(Margin(-30, -30, 0, 0));
    rp1->setAlign(RELATIVE_ALIGN_PARENT_TOP_LEFT);
    button->setLayoutParameter(rp1);
    
    _inventory = Inventory::create();
    this->addChild(_inventory);
*/
    return true;
}

/*
void UserInterfaceLayer::touchEvent(Button *pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            log("UIButton Click.");
            
            break;
        case TOUCH_EVENT_MOVED:
            
            // TODO
            break;
        case TOUCH_EVENT_ENDED:
            //_inventory->hide();
            // TODO
            if(_inventory->isVisible())
            {
                _inventory->setVisible(false);
            }
            else
            {
                _inventory->setVisible(true);
            }
            break;
        case TOUCH_EVENT_CANCELED:
            // TODO
            break;
        default:
            // TODO
            break;
    }
}
 */
