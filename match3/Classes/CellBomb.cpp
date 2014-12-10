//
//  CellBomb.cpp
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#include "CellBomb.h"


void CellBomb::deactivate(Vector<Cell *> *itemsSnake)
{
    //log("Deactivate bomb %d %d activated=%d",_x,_y, activated);
    
    if(activated)
    {
        log("Deactivate bomb %d %d",_x,_y);
        activated = false;
        
        for(Cell *cell : activatedItems)
        {
            if(!itemsSnake->contains(cell))
                cell->setShouldDelete(false);
            
            cell->getWillExplodeSprite()->setVisible(false);
                
            // деактивация других бомб
            if(cell->getType() >= Bomb0 && cell->getType() <= Bomb2)
            {
                if(!((CellBomb *)cell)->getWasActivatedByChain())
                {
                    ((CellBomb *)cell)->deactivate(itemsSnake);
                }
                //log("Deactivate cell who bomb %d %d byChain=%d",cell->getX(),cell->getY(),((CellBomb *)cell)->getWasActivatedByChain());
            }
            else
            {
                //log("Deactivate cell %d %d",cell->getX(),cell->getY());
            }
        }
        activatedItems.clear();
    }
}