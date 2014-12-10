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

USING_NS_CC;

GameScene *GameScene::_instance = NULL;

GameScene *GameScene::getInstance()
{
    return _instance;
}

Scene *GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    _instance = (GameScene *)layer;
    
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
    
    _hero = Hero::create();
    _enemy = Enemy::create();
    
    auto backgroundLayer = BackgroundLayer::create();
    this->addChild(backgroundLayer, BackLayer, BackLayer);
    
    auto gameObjectsLayer = GameObjectsLayer::create();
    this->addChild(gameObjectsLayer, GameLayer, GameLayer);
    
    auto userInterfaceLayer = UserInterfaceLayer::create();
    this->addChild(userInterfaceLayer, UILayer, UILayer);
    

    
    return true;
}

GameObjectsLayer *GameScene::getGameObjectsLayer()
{
    this->getDescription();
    Node *layer = this->getChildByTag(GameLayer);
    return (GameObjectsLayer *)layer;
}

UserInterfaceLayer *GameScene::getUserInterfaceLayer()
{
    this->getDescription();
    Node *layer = this->getChildByTag(UILayer);
    return (UserInterfaceLayer *)layer;
}

