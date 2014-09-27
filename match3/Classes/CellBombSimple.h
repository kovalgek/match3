//
//  CellBombSimple.h
//  match3
//
//  Created by Anton Kovalchuk on 27.09.14.
//
//

#ifndef __match3__CellBombSimple__
#define __match3__CellBombSimple__

#include "CellBomb.h"

class CellBombSimple : public CellBomb
{
    virtual void activate(std::vector<Vector<Cell *>*> *items, Vector<Cell *> *itemsSnake, bool activatedByChain);
};

#endif /* defined(__match3__CellBombSimple__) */
