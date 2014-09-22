//
//  CellSimple.cpp
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#include "CellSimple.h"


bool CellSimple::init(int x, int y, CellType type)
{
    int bottle = arc4random()%4;
    char numStr[256];
    sprintf(numStr, "bottle%d.png", bottle);
    _mainSprite = Sprite::create(numStr);
    this->addChild(_mainSprite, 1);
    
    if (!CellStacked::init(x, y, type))
    {
        return false;
    }
    

    
    return true;
}