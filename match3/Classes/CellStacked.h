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
    virtual bool init(int x, int y, CellType type);
    CC_SYNTHESIZE(CellDelegate *, _delegate, Delegate);
    
    CC_SYNTHESIZE(Sprite *, _arrowSprite, ArrowSprite);
    
    void setState(CellStates var);
    CellStates getState();

protected:
    CellStates state;
};

#endif /* defined(__match3__CellStacked__) */
