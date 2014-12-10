//
//  Cell.h
//  match3
//
//  Created by Anton Kovalchuk on 13.09.14.
//
//

#ifndef __match3__Cell__
#define __match3__Cell__

#include "cocos2d.h"

USING_NS_CC;

enum CellType
{
    Bottle0,
    Bottle1,
    Bottle2,
    Bottle3,
    Bottle4,
    Bomb0,
    Bomb1,
    Bomb2,
    Wall,
    Enemy
};

enum CellStates
{
    Normal,
    Activated
};

class CellDelegate;

class Cell : public Node
{
public:
    static Cell *create(int x, int y, CellType type);
    virtual bool init(int x, int y, CellType type);

    CC_SYNTHESIZE_READONLY(Sprite *, _mainSprite, MainSprite);
    
    CC_SYNTHESIZE_READONLY(Sprite *, _willExplodeSprite, WillExplodeSprite);
    
    CC_SYNTHESIZE(int, _x, X);
    CC_SYNTHESIZE(int, _y, Y);
    
    CC_SYNTHESIZE_READONLY(CellType, _type, Type);
    
    CC_SYNTHESIZE(bool, _shouldDelete, ShouldDelete);
    
private:
    Sprite *selectImage;
};

#endif /* defined(__match3__Cell__) */
