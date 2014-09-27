//
//  CellBomb.cpp
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#include "CellBomb.h"
#include "GameObjectsLayer.h"

void CellBomb::activate(std::vector<Vector<Cell *>*> *items, Vector<Cell *> *itemsSnake, bool activatedByChain)
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
                    
                    if(!itemsSnake->contains(cellForBomb) && !cellForBomb->getWillExplodeSprite()->isVisible())
                    {
                        if(cellForBomb->getType() >= Bottle0 && cellForBomb->getType() <= Bottle4)
                        {
                            
                            log("activate near bomb bottles %d %d",cellForBomb->getX(),cellForBomb->getY());
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
          
                            next = (CellBomb *)cellForBomb;
                            next->activate(items, itemsSnake, false);
                        }
                    }
                }
            }
        }
    }
}

void CellBomb::deactivate()
{
    //log("Deactivate bomb %d %d activated=%d",_x,_y, activated);
    
    if(activated)
    {
        log("Deactivate bomb %d %d",_x,_y);
        activated = false;
        
        for(Cell *cell : activatedItems)
        {
            cell->setShouldDelete(false);
            cell->getWillExplodeSprite()->setVisible(false);
            
            // деактивация других бомб
            if(cell->getType() >= Bomb0 && cell->getType() <= Bomb2)
            {
                if(!((CellBomb *)cell)->getWasActivatedByChain())
                {
                    ((CellBomb *)cell)->deactivate();
                }
                //log("Deactivate cell who bomb %d %d byChain=%d",cell->getX(),cell->getY(),((CellBomb *)cell)->getWasActivatedByChain());
            }
            else
            {
                //log("Deactivate cell %d %d",cell->getX(),cell->getY());
            }
        }
        
        activatedItems.clear();
        //log("counr=%d",activatedItems.size());
    }
}