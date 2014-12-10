//
//  CellBombSimple.cpp
//  match3
//
//  Created by Anton Kovalchuk on 27.09.14.
//
//

#include "CellBombSimple.h"
#include "GameObjectsLayer.h"

void CellBombSimple::activate(std::vector<Vector<Cell *>*> *items, Vector<Cell *> *itemsSnake, bool activatedByChain)
{
    if(!activated)
    {
        activated = true;
        _wasActivatedByChain = activatedByChain;
        
        log("activate BOMB %d %d %d",_x,_y,_wasActivatedByChain);
        
        for(int columnShift = -1; columnShift <= 1; ++columnShift)
        {
            for(int rowShift = -1; rowShift <= 1; ++rowShift)
            {
                if((_x + columnShift >= 0 && _x + columnShift < GameObjectsLayer::slotsWidth) &&
                   (_y + rowShift >= 0 && _y + rowShift < GameObjectsLayer::slotsHeight))
                {
                    Cell *cellForBomb = items->at(_x + columnShift)->at(_y + rowShift);
                    
                    if(!cellForBomb->getWillExplodeSprite()->isVisible())
                    {
                        if(cellForBomb->getType() >= Bottle0 && cellForBomb->getType() <= Bottle4)
                        {
                            log("activate near bomb bottles %d %d",cellForBomb->getX(),cellForBomb->getY());
                            
                            //if(!itemsSnake->contains(cellForBomb))
                                activatedItems.pushBack(cellForBomb);
                            
                            
                            cellForBomb->setShouldDelete(true);
                            cellForBomb->getWillExplodeSprite()->setVisible(true);
                        }
                    }
                }
            }
        }
        
        for(int columnShift = -1; columnShift <= 1; ++columnShift)
        {
            for(int rowShift = -1; rowShift <= 1; ++rowShift)
            {
                if((_x + columnShift >= 0 && _x + columnShift < GameObjectsLayer::slotsWidth) &&
                   (_y + rowShift >= 0 && _y + rowShift < GameObjectsLayer::slotsHeight))
                {
                    Cell *cellForBomb = items->at(_x + columnShift)->at(_y + rowShift);
                    
                    if(!cellForBomb->getWillExplodeSprite()->isVisible())
                    {
                        if(cellForBomb->getType() >= Bomb0 && cellForBomb->getType() <= Bomb2)
                        {
                            log("activate near bomb BOMB %d %d",cellForBomb->getX(),cellForBomb->getY());
                            
                            activatedItems.pushBack(cellForBomb);
                            
                            cellForBomb->setShouldDelete(true);
                            cellForBomb->getWillExplodeSprite()->setVisible(true);
                            
                            ((CellBomb *)cellForBomb)->activate(items, itemsSnake, false);
                        }
                    }
                }
            }
        }
    }
}