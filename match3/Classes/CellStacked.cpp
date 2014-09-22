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
    
    char numStr[256];
    
    if(type >= Bottle0 && type <= Bottle4)
        sprintf(numStr, "bottle%d.png", type);
    else if(type >= Bomb0 && type <= Bomb2)
        sprintf(numStr, "bomb%d.png", type - Bottle4 - 1);
    
    _mainSprite = Sprite::create(numStr);
    this->addChild(_mainSprite, 1);
    
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
            state = Activated;
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