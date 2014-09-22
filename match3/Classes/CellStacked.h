//
//  CellStacked.h
//  match3
//
//  Created by Anton Kovalchuk on 21.09.14.
//
//

#ifndef __match3__CellStacked__
#define __match3__CellStacked__

#include "Cell.h"

class CellStacked : public Cell
{
public:
    //static Cell *create(int x, int y);
    //virtual bool init(int x, int y);
    virtual bool init(int x, int y, CellType type);
    
    CC_SYNTHESIZE(CellDelegate *, _delegate, Delegate);
private:
};

#endif /* defined(__match3__CellStacked__) */
