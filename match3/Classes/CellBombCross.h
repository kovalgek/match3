//
//  CellBombCross.h
//  match3
//
//  Created by Anton Kovalchuk on 27.09.14.
//
//

#ifndef __match3__CellBombCross__
#define __match3__CellBombCross__

#include "CellBomb.h"

class CellBombCross : public CellBomb
{
    virtual void activate(std::vector<Vector<Cell *>*> *items, Vector<Cell *> *itemsSnake, bool activatedByChain);
};

#endif /* defined(__match3__CellBombCross__) */
