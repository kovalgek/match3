//
//  UserInterfaceLayer.cpp
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#include "UserInterfaceLayer.h"
#include "GameScene.h"
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
    Hero *hero = GameScene::getInstance()->getHero();
    
    char heroHealth[256];
    sprintf(heroHealth, "%d/%d", hero->getHealth(), hero->getMaxHealth());
    labelHeroHealth = Label::createWithBMFont("font.fnt", heroHealth);
    labelHeroHealth->setPosition(Point(155,85));
    topSprite->addChild(labelHeroHealth,2);
    
    char damageHero[256];
    sprintf(damageHero, "Damage:%d", hero->getDamage());
    labelHeroDamage = Label::createWithBMFont("font.fnt", damageHero);
    labelHeroDamage->setScale(0.7f);
    labelHeroDamage->setPosition(Point(100,30));
    topSprite->addChild(labelHeroDamage,2);
    
    char rageHero[256];
    sprintf(rageHero, "Rage:%d", hero->getDamage());
    labelHeroRage = Label::createWithBMFont("font.fnt", rageHero);
    labelHeroRage->setScale(0.7f);
    labelHeroRage->setPosition(Point(100,10));
    topSprite->addChild(labelHeroRage,2);
    
    
    Enemy *enemy = GameScene::getInstance()->getEnemy();
    
    char enemyHealth[256];
    sprintf(enemyHealth, "%d/%d", enemy->getHealth(), enemy->getMaxHealth());
    auto labelEnemyHealth = Label::createWithBMFont("font.fnt", enemyHealth);
    labelEnemyHealth->setPosition(Point(visibleSize.width - 150,85));
    topSprite->addChild(labelEnemyHealth,2);
    
    char damageEnemy[256];
    sprintf(damageEnemy, "Damage:%d", enemy->getDamage());
    auto labelEnemyDamage = Label::createWithBMFont("font.fnt", damageEnemy);
    labelEnemyDamage->setScale(0.7f);
    labelEnemyDamage->setPosition(Point(visibleSize.width - 100,30));
    topSprite->addChild(labelEnemyDamage,2);
    
    char frequencyEnemy[256];
    sprintf(frequencyEnemy, "%d", enemy->getFrequency());
    auto labelEnemyFrequency = Label::createWithBMFont("font.fnt", frequencyEnemy);
    labelEnemyFrequency->setScale(1.5f);
    labelEnemyFrequency->setPosition(Point(visibleSize.width/2,90));
    topSprite->addChild(labelEnemyFrequency,2);
    */
    return true;
}

void UserInterfaceLayer::updateInterface()
{
    Hero *hero = GameScene::getInstance()->getHero();
    
    char heroHealth[256];
    sprintf(heroHealth, "%d/%d", hero->getHealth(), hero->getMaxHealth());
    labelHeroHealth->setString(heroHealth);
    
    char damageHero[256];
    sprintf(damageHero, "Damage:%d", hero->getDamage());
    labelHeroDamage->setString(damageHero);
    
    char rageHero[256];
    sprintf(rageHero, "Rage:%d", hero->getDamage());
    labelHeroRage->setString(rageHero);
    
    /*
    Enemy *enemy = GameScene::getInstance()->getEnemy();
    
    char enemyHealth[256];
    sprintf(enemyHealth, "%d/%d", enemy->getHealth(), enemy->getMaxHealth());
    auto labelEnemyHealth = Label::createWithBMFont("font.fnt", enemyHealth);
    labelEnemyHealth->setPosition(Point(visibleSize.width - 150,85));
    topSprite->addChild(labelEnemyHealth,2);
    
    char damageEnemy[256];
    sprintf(damageEnemy, "Damage:%d", enemy->getDamage());
    auto labelEnemyDamage = Label::createWithBMFont("font.fnt", damageEnemy);
    labelEnemyDamage->setScale(0.7f);
    labelEnemyDamage->setPosition(Point(visibleSize.width - 100,30));
    topSprite->addChild(labelEnemyDamage,2);
    
    char frequencyEnemy[256];
    sprintf(frequencyEnemy, "%d", enemy->getFrequency());
    auto labelEnemyFrequency = Label::createWithBMFont("font.fnt", frequencyEnemy);
    labelEnemyFrequency->setScale(1.5f);
    labelEnemyFrequency->setPosition(Point(visibleSize.width/2,90));
    topSprite->addChild(labelEnemyFrequency,2);
     */
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
