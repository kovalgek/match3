//
//  Cell.cpp
//  match3
//
//  Created by Anton Kovalchuk on 13.09.14.
//
//

#include "Cell.h"
#include "CellStacked.h"
#include "CellBombSimple.h"
#include "CellBombCross.h"

USING_NS_CC;

Cell *Cell::create(int x, int y, CellType type)
{
    Cell *pRet = 0;
    
    if(type >= Bottle0 && type <= Bottle4)
        pRet = new CellStacked();
    else if(type == Bomb0)
        pRet = new CellBombSimple();
    else if(type == Bomb1)
        pRet = new CellBombCross();
    
    if (pRet && pRet->init(x, y, type))
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

bool Cell::init(int x, int y, CellType type)
{
    if (!Node::init())
    {
        return false;
    }
    
    _type = type;
    
    _x = x;
    _y = y;
    
    _willExplodeSprite = Sprite::create("Selected_cell.png");
    this->addChild(_willExplodeSprite, 0);
    _willExplodeSprite->setVisible(false);
    
    _inSnakeSprite = Sprite::create("Green_cell.png");
    this->addChild(_inSnakeSprite, 0);
    _inSnakeSprite->setVisible(false);
    
    char qwe[256];
    sprintf(qwe, "%d,%d", _x,_y);

    auto label = LabelTTF::create(qwe, "Arial", 14);
    label->setPosition(Point(-40,40));
    this->addChild(label,2);
    
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
        _inSnakeSprite->setVisible(true);
    else if(state == Normal)
        _inSnakeSprite->setVisible(false);
}

