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
    
public:
    
    static cocos2d::Scene* createScene();
    //static GameScene *createScene(Scenes scene);
    CREATE_FUNC(GameScene);
    virtual bool init();
    //void menuCloseCallback(cocos2d::Ref *pSender);
    //static RootScene *getInstance();
    
    //GameObjectsLayer *getGameObjectsLayer();
    //UserInterfaceLayer *getUserInterfaceLayer();
    //BackgroundLayer *getBackgroundLayer();
};
#endif /* defined(__match3__GameScene__) */
