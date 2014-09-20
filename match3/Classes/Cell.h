//
//  Cell.h
//  match3
//
//  Created by Anton Kovalchuk on 13.09.14.
//
//

#ifndef __match3__Cell__
#define __match3__Cell__

#include "cocos2d.h"

USING_NS_CC;

enum CellStates
{
    Normal,
    Activated
};

class CellDelegate;

class Cell : public Node
{
public:
    static Cell *create(int x, int y);
    virtual bool init(int x, int y);
    //CREATE_FUNC(Cell);
    CC_SYNTHESIZE_READONLY(Sprite *, _mainImage, MainImage);
    CC_SYNTHESIZE_READONLY(Sprite *, _hightlightSprite, HightlightSprite);
    CC_SYNTHESIZE(int, _x, X);
    CC_SYNTHESIZE(int, _y, Y);
    CC_SYNTHESIZE_READONLY(int, _type, Type);
    //CC_SYNTHESIZE(int, _state, State);
    CC_SYNTHESIZE(CellDelegate *, _delegate, Delegate);
    
    CC_SYNTHESIZE(bool, _shouldDelete, ShouldDelete);
    
    void setState(CellStates var);
    CellStates getState();
private:
    CellStates state;
    //Sprite *image;
    Sprite *selectImage;
    
};

#endif /* defined(__match3__Cell__) */
