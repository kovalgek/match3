//
//  GameScene.h
//  match3
//
//  Created by Anton Kovalchuk on 13.09.14.
//
//

#ifndef __match3__GameScene__
#define __match3__GameScene__

#include "cocos2d.h"
#include "Hero.h"
#include "Enemy.h"

typedef enum
{
    BackLayer,
	GameLayer,
	UILayer
} LayerTags;

class GameObjectsLayer;
class UserInterfaceLayer;
class BackgroundLayer;

class GameScene : cocos2d::Scene
{
    static GameScene *_instance;
public:
    
    static Scene *createScene();
    CREATE_FUNC(GameScene);
    virtual bool init();
    //void menuCloseCallback(cocos2d::Ref *pSender);
    static GameScene *getInstance();
    
    GameObjectsLayer *getGameObjectsLayer();
    UserInterfaceLayer *getUserInterfaceLayer();
    //BackgroundLayer *getBackgroundLayer();
    
    CC_SYNTHESIZE_READONLY(Hero *, _hero, Hero);
    CC_SYNTHESIZE_READONLY(class Enemy *, _enemy, Enemy);
    //Enemy *enemy;
};
#endif /* defined(__match3__GameScene__) */
