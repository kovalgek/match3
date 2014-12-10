//
//  GameObjectsLayer.h
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#ifndef __QuestGame__GameObjectsLayer__
#define __QuestGame__GameObjectsLayer__

#include "cocos2d.h"
#include "Cell.h"
#include "CellDelegate.h"


USING_NS_CC;

class GameObjectsLayer : public cocos2d::Layer, public CellDelegate
{
    int cellType;
    std::vector<Vector<Cell *>*> items;
    Vector<Cell *> itemsSnake;
    CellType snakeType;
    
    
    virtual void activateSnake(Cell *cell);
    virtual void searchCells(Point point);
    virtual void closeSnake();
public:
    
    //cocos2d::Node *content;
    
    //CC_SYNTHESIZE_READONLY(Hero *, hero, Hero);
    //CC_SYNTHESIZE_READONLY(Vector<GameObject *>, gameObjects, GameObjects);
    
    //virtual bool init(RootScene *scene);
    //virtual void add2inventory(CollectObject *collectObject);
    
    virtual bool init();
    CREATE_FUNC(GameObjectsLayer);
    
    static int slotsWidth;
    static int slotsHeight;
    static int slotShiftLeft;
    static int slotShiftBottom;
    static int slotSizeWidth;
    static int slotSizeHeight;
    
    static int minSnakeSizeActivation;
    
protected:
    //RootScene *rootScene;
};

#endif /* defined(__QuestGame__GameObjectsLayer__) */
