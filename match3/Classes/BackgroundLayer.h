//
//  BackgroundLayer.h
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#ifndef __QuestGame__BackgroundLayer__
#define __QuestGame__BackgroundLayer__

#include "cocos2d.h"
//#include "RootScene.h"


class BackgroundLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(BackgroundLayer);
};


#endif /* defined(__QuestGame__BackgroundLayer__) */
