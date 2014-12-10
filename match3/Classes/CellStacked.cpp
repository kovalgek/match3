//
//  CellStacked.cpp
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#include "CellStacked.h"
#include "CellDelegate.h"

bool CellStacked::init(int x, int y, CellType type)
{
    if (!Cell::init(x, y, type))
    {
        return false;
    }
    
    _arrowSprite = Sprite::create("arrow.png");
    _arrowSprite->setAnchorPoint(Vec2(0.7f,0.5f));
    _arrowSprite->setVisible(false);
    //_arrowSprite->setPosition(45,0);
    //_arrowSprite->setRotation(45.0f);
    this->addChild(_arrowSprite,0);
    
    char numStr[256];
    if(type >= Bottle0 && type <= Bottle4)
        sprintf(numStr, "bottle%d.png", type);
    else if(type >= Bomb0 && type <= Bomb2)
        sprintf(numStr, "bomb%d.png", type - Bottle4 - 1);
    _mainSprite = Sprite::create(numStr);
    this->addChild(_mainSprite, 1);
    
    char snakeSpriteName[256];
    if(type >= Bottle0 && type <= Bottle4)
    {
        sprintf(snakeSpriteName, "bottleSnake%d.png", type);
    }
    else
    {
        sprintf(snakeSpriteName, "Green_cell.png");
    }
    _inSnakeSprite = Sprite::create(snakeSpriteName);
    this->addChild(_inSnakeSprite, 2);
    _inSnakeSprite->setVisible(false);
    
    char snakeSpriteName2[256];
    if(type >= Bottle0 && type <= Bottle4)
    {
        sprintf(snakeSpriteName2, "bottleBombed%d.png", type);
    }
    else
    {
        sprintf(snakeSpriteName2, "Green_cell.png");
    }
    _inSnakeSprite2 = Sprite::create(snakeSpriteName2);
    this->addChild(_inSnakeSprite2, 3);
    _inSnakeSprite2->setVisible(false);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this](Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        
        Point locationInNode = _mainSprite->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))
        {
            //state = Activated;
            _shouldDelete = true;
            
            _delegate->activateSnake(this);
            _inSnakeSprite->setVisible(true);
            return true;
        }
        return false;
    };
    
    listener->onTouchMoved = [this](Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        
        Point locationInNode = _mainSprite->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        _delegate->searchCells(touch->getLocation());
    };
    
    listener->onTouchEnded = [this](Touch *touch, Event *event)
    {
        _delegate->closeSnake();
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _mainSprite);

    return true;
}

CellStates CellStacked::getState()
{
    return state;
}

void CellStacked::setState(CellStates var)
{
    state = var;
    if(state == Activated)
    {
        //_mainSprite->setVisible(false);
        _inSnakeSprite->setVisible(true);
        //_arrowSprite->setVisible(true);
    }
    else if(state == Normal)
    {
        //_mainSprite->setVisible(true);
        _inSnakeSprite->setVisible(false);
        _inSnakeSprite2->setVisible(false);
        if(_arrowSprite)
        {
            //_arrowSprite->removeFromParent();
            //_arrowSprite->setVisible(false);
        }
    }
}
