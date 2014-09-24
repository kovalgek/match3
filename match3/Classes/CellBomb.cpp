//
//  CellBomb.cpp
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#include "CellBomb.h"
#include "GameObjectsLayer.h"

void CellBomb::activate(std::vector<Vector<Cell *>*> *items, bool activate)
{
    for(int columnShift = -1; columnShift <= 1; ++columnShift)
    {
        for(int rowShift = -1; rowShift <= 1; ++rowShift)
        {
            if((_x + columnShift >= 0 && _x + columnShift < GameObjectsLayer::slotsWidth) &&
               (_y + rowShift >= 0 && _y + rowShift < GameObjectsLayer::slotsHeight))
            {
                log("x=%d y=%d",_x + columnShift,_y + rowShift);
                Cell *cellForBomb = items->at(_x + columnShift)->at(_y + rowShift);
                
                cellForBomb->setShouldDelete(activate);
                cellForBomb->getWillExplodeSprite()->setVisible(activate);
            }
        }
    }
}