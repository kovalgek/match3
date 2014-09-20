//
//  SwitchDelegate.h
//  QuestGame2
//
//  Created by Антон Ковальчук on 13.04.14.
//
//

#ifndef QuestGame2_SwitchDelegate_h
#define QuestGame2_SwitchDelegate_h

class Cell;

class CellDelegate
{
public:
    virtual void activateSnake(Cell *cell) = 0;
    virtual void searchCells(Point point) = 0;
    virtual void closeSnake() = 0;
};

#endif
