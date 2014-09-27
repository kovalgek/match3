//
//  CellBombCross.cpp
//  match3
//
//  Created by Anton Kovalchuk on 27.09.14.
//
//

#include "CellBombCross.h"
#include "GameObjectsLayer.h"

void CellBombCross::activate(std::vector<Vector<Cell *>*> *items, Vector<Cell *> *itemsSnake, bool activatedByChain)
{
    
    if(!activated)
    {
        activated = true;
        _wasActivatedByChain = activatedByChain;
        
        log("activate BOMB %d %d %d",_x,_y,_wasActivatedByChain);
        
        for(Vector<Cell *> *line : *items)
        {
            Cell *cellForBomb = line->at(_y);
            
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
        
        for(Cell *cellForBomb : *items->at(_x))
        {
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
        //bomb
        for(Vector<Cell *> *line : *items)
        {
            Cell *cellForBomb = line->at(_y);
            
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
        
        for(Cell *cellForBomb : *items->at(_x))
        {
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