//
//  GameScene.cpp
//  match3
//
//  Created by Anton Kovalchuk on 13.09.14.
//
//

#include "GameScene.h"
#include "UserInterfaceLayer.h"
#include "GameObjectsLayer.h"
#include "BackgroundLayer.h"

Scene *GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        //_instance = this;
        return false;
    }
    
    auto backgroundLayer = BackgroundLayer::create();
    this->addChild(backgroundLayer, BackLayer, BackLayer);
    
    auto gameObjectsLayer = GameObjectsLayer::create();
    this->addChild(gameObjectsLayer, GameLayer, GameLayer);
    
    auto userInterfaceLayer = UserInterfaceLayer::create();
    this->addChild(userInterfaceLayer, UILayer, UILayer);
    
    return true;
}