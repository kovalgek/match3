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
public:
    void activate(std::vector<Vector<Cell *>*> *items, bool activate);
   // void deactivate();
};

#endif /* defined(__match3__CellBomb__) */
