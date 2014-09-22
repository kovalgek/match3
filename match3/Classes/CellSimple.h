//
//  CellSimple.h
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#ifndef __match3__CellSimple__
#define __match3__CellSimple__

#include "CellStacked.h"

class CellSimple : public CellStacked
{
    virtual bool init(int x, int y, CellType type);
};

#endif /* defined(__match3__CellSimple__) */
