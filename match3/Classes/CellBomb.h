//
//  CellBomb.h
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#ifndef __match3__CellBomb__
#define __match3__CellBomb__

#include "CellStacked.h"

class CellBomb : public CellStacked
{
protected:
    bool activated;
    Vector<Cell *> activatedItems;
public:
    virtual void activate(std::vector<Vector<Cell *>*> *items, Vector<Cell *> *itemsSnake, bool activatedByChain) = 0;
    void deactivate(Vector<Cell *> *itemsSnake);
    CC_SYNTHESIZE_READONLY(bool, _wasActivatedByChain, WasActivatedByChain);
};

#endif /* defined(__match3__CellBomb__) */
