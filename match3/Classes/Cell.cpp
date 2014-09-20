//
//  Cell.cpp
//  match3
//
//  Created by Anton Kovalchuk on 13.09.14.
//
//

#include "Cell.h"
#include "CellDelegate.h"

USING_NS_CC;


Cell *Cell::create(int x, int y)
{
    Cell *pRet = new Cell();
    if (pRet && pRet->init(x, y))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Cell::init(int x, int y)
{
    if (!Node::init())
    {
        return false;
    }
    
    _x = x;
    _y = y;
    
    
    _hightlightSprite = Sprite::create("Selected_cell.png");
    this->addChild(_hightlightSprite, 0);
    _hightlightSprite->setVisible(false);
    
    _mainImage = Sprite::create("Blue_cell.png");
    this->addChild(_mainImage, 1);
    
    
    
    _type = arc4random()%3;
    char numStr[256];
    sprintf(numStr, "%d", _type);
    
    auto label = LabelTTF::create(numStr, "Arial", 24);
    label->setPosition(Point(0,0));
    this->addChild(label,2);
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this](Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        
        Point locationInNode = _mainImage->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        if (rect.containsPoint(locationInNode))
        {
            _delegate->activateSnake(this);
            state = Activated;
            _shouldDelete = true;
            _hightlightSprite->setVisible(true);
            return true;
        }
        return false;
    };
    
    listener->onTouchMoved = [this](Touch *touch, Event *event)
    {
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        
        Point locationInNode = _mainImage->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        
        
        //if (!rect.containsPoint(locationInNode))
        {
            int shiftX = 0;
            int shiftY = 0;
            
            if(locationInNode.x > s.width)
                shiftX = 1;
            else if(locationInNode.x < 0)
                shiftX = -1;
            else if(locationInNode.y < 0)
                shiftY = -1;
            else if(locationInNode.y > s.height)
                shiftY = 1;
            
            _delegate->searchCells(touch->getLocation());
            //log("moved locationInNode.x=%f _type=%d",locationInNode.x, _type);
        }
    };
    
    listener->onTouchEnded = [this](Touch *touch, Event *event)
    {
        log("end");
        _delegate->closeSnake();
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _mainImage);
    
    return true;
}

CellStates Cell::getState()
{
    return state;
}

void Cell::setState(CellStates var)
{
    state = var;
    if(state == Activated)
        _hightlightSprite->setVisible(true);
    else if(state == Normal)
        _hightlightSprite->setVisible(false);
}

