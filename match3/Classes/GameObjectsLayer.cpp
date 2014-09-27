//
//  GameObjectsLayer.cpp
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#include "GameObjectsLayer.h"
#include "Cell.h"
#include "CellSimple.h"
#include "CellBomb.h"
/*
#include "Hero.h"
#include "RootScene.h"
#include "UserInterfaceLayer.h"
#include "Inventory.h"
#include "InventoryObject.h"
#include "BackgroundLayer.h"
*/
USING_NS_CC;

int GameObjectsLayer::slotsWidth  = 7;
int GameObjectsLayer::slotsHeight = 8;
int GameObjectsLayer::slotShiftLeft = 52;
int GameObjectsLayer::slotShiftBottom = 50;
int GameObjectsLayer::slotSizeWidth = 91.0f;
int GameObjectsLayer::slotSizeHeight = 91.0f;

int GameObjectsLayer::minSnakeSizeActivation = 3;

enum SnakeActivation
{
    MinSnakeSize = 3,
    BombActivation0 = 4,
    BombActivation1 = 7,
    BombActivation2 = 14
};

// on "init" you need to initialize your instance
bool GameObjectsLayer ::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    
    // items = Vector<Vector<Cell *>>(7);
   
    for(int column = 0; column < slotsWidth; ++column)
    {
        Vector<Cell *> *line = new Vector<Cell *>();
        
        for(int row = 0; row < slotsHeight; ++row)
        {
            int bottle = arc4random()%4;
            
            CellStacked *cell = NULL;
            
            if((column == 3 && (row == 4 || row == 5)) ||
                (column == 4 && row == 6))
                cell = (CellStacked *)Cell::create(column, row, (CellType)Bomb0);
            else
                cell = (CellStacked *)Cell::create(column, row, (CellType)bottle);
            
            cell->setDelegate(this);
            cell->setPosition(Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + row * slotSizeHeight));
            this->addChild(cell, 1);
            line->pushBack(cell);
        }
        items.push_back(line);
    }
    
    return true;
}

void GameObjectsLayer::activateSnake(Cell *cell)
{
    cell->setLocalZOrder(100);
    itemsSnake.pushBack(cell);
    snakeType = cell->getType();
}

void GameObjectsLayer::searchCells(Point point)
{
    for(int column = 0; column < slotsWidth; ++column)
    {
        Vector<Cell *> *line = items.at(column);
        
        for(int row = 0; row < slotsHeight; ++row)
        {
            Cell *cell = line->at(row);
        
            Size size = cell->getMainSprite()->getContentSize();
            Rect rect = Rect(cell->getPosition().x - size.width * 0.5f, cell->getPosition().y - size.height * 0.5f, size.width, size.height);

            if (rect.containsPoint(point) && ((snakeType == cell->getType()) ||
                                              (snakeType >= Bomb0 && snakeType <= Bomb2) ||
                                              (cell->getType() >= Bomb0 && cell->getType() <= Bomb2)))
            {
                int index = (int)itemsSnake.getIndex(cell);
                
                if(index == -1)
                {
                    if(abs(itemsSnake.back()->getX() - cell->getX()) <= 1 &&
                       abs(itemsSnake.back()->getY() - cell->getY()) <= 1)
                    {
                        if(snakeType >= Bomb0 && snakeType <= Bomb2) // если начали с бомбы, то заем змейке тип
                            snakeType = cell->getType();
                        
                        cell->setShouldDelete(true);
                        //cell->getInSnakeSprite()->setVisible(true);
                        
                        
                        
                        Sprite *_arrowSprite = ((CellStacked *)cell)->getArrowSprite();
                        //this->addChild(_arrowSprite,0);
                        
                        if(itemsSnake.back()->getY() == cell->getY())
                        {
                            if(itemsSnake.back()->getX() > cell->getX())
                                _arrowSprite->setRotation(180.0f);
                            else
                                _arrowSprite->setRotation(0.0f);
                        }
                        else if(itemsSnake.back()->getY() < cell->getY())
                        {
                            if(itemsSnake.back()->getX() == cell->getX())
                                _arrowSprite->setRotation(270.0f);
                            else if(itemsSnake.back()->getX() > cell->getX())
                                _arrowSprite->setRotation(270.0f - 45.0f);
                            else
                                _arrowSprite->setRotation(270.0f + 45.0f);
                        }
                        else
                        {
                            if(itemsSnake.back()->getX() == cell->getX())
                                _arrowSprite->setRotation(90.0f);
                            else if(itemsSnake.back()->getX() < cell->getX())
                                _arrowSprite->setRotation(90.0f - 45.0f);
                            else
                                _arrowSprite->setRotation(90.0f + 45.0f);
                        }
                        cell->setLocalZOrder(100 - (int)itemsSnake.size());
                        log("order=%d",cell->getOrderOfArrival());
                       // ((CellStacked *)cell)->setArrowSprite(_arrowSprite);
                        
                        
                        ((CellStacked *)cell)->setState(Activated);
                        
                        
                        itemsSnake.pushBack(cell);
                        
                        // активация бомб
                        for(Cell *potentialBombCell : itemsSnake)
                        {
                            if(itemsSnake.size() >= MinSnakeSize &&
                               (potentialBombCell->getType() >= Bomb0 &&
                                potentialBombCell->getType() <= Bomb2))
                            {
                                CellBomb *cellBomb = (CellBomb *)potentialBombCell;
                                log("cellBomb=%d",cellBomb->getType());
                                cellBomb->activate(&items, &itemsSnake, true);
                            }
                        }
                    }
                    //log("AHTING");
                }
                else
                {
                    // если начинали с бомбы и вернулись обратно, то сбрасываем тип
                    if(itemsSnake.size() == 1 && itemsSnake.back()->getType() >= Bomb0 && itemsSnake.back()->getType() <= Bomb2)
                        snakeType = itemsSnake.back()->getType();
                    
                    // идем по отделившемуся хвосту змейки и деактивируем бомбы, удаление отменяем
                    //log("index=%d",index);
                    Vector<Cell *>::iterator iter;
                    
                    for(int i = (int)itemsSnake.size() - 1; i > index; --i)
                    {
                        if(itemsSnake.at(i)->getType() >= Bomb0 &&
                           itemsSnake.at(i)->getType() <= Bomb2)
                        {
                            CellBomb *cellBomb = (CellBomb *)itemsSnake.at(i);
                            if(cellBomb->getWasActivatedByChain())
                                cellBomb->deactivate();
                        }
                        //log("i=%d itemsSnake.at(i)Type=%d",i,itemsSnake.at(i)->getType());
                        
                        //((CellStacked *)itemsSnake.at(i))->getArrowSprite()->setVisible(false);
                        
                        //itemsSnake.at(i)->getInSnakeSprite()->setVisible(false);
                        itemsSnake.at(i)->setShouldDelete(false);
                        ((CellStacked *)itemsSnake.at(i))->setState(Normal);
                        itemsSnake.erase(i);
                    }
                    
                    // если в змейке есть бомбы и змейка стала маленькой, то деактивируем их
                    for(Cell *potentialBombCell : itemsSnake)
                    {
                        if((potentialBombCell->getType() >= Bomb0 &&
                            potentialBombCell->getType() <= Bomb2)
                           && itemsSnake.size() < MinSnakeSize)
                        {
                            CellBomb *cellBomb = (CellBomb *)potentialBombCell;
                            if(cellBomb->getWasActivatedByChain())
                                cellBomb->deactivate();
                        }
                    }
                }
            }
        }
    }
}

void GameObjectsLayer::closeSnake()
{
    if(itemsSnake.size() >= MinSnakeSize)
    {
        CellStacked *lastCell = (CellStacked *)itemsSnake.back();
        
        // add new
        for(int column = 0; column < slotsWidth; ++column)
        {
            int shouldDeleteCountInColumn = 0;
            
            for(Cell *cell : *items.at(column))
            {
                if(cell->getShouldDelete())
                {
                    ++shouldDeleteCountInColumn;
                }
            }
            
            if(lastCell->getX() == column && itemsSnake.size() >= BombActivation0)
            {
                --shouldDeleteCountInColumn;;
                
                
                CellType cellType;
                
                if(itemsSnake.size() >= BombActivation0 && itemsSnake.size() < BombActivation1)
                    cellType = Bomb0;
                else if(itemsSnake.size() >= BombActivation1)
                    cellType = Bomb1;
                
                CellBomb *newCell = (CellBomb *)Cell::create(column, lastCell->getY(), cellType);
                newCell->setDelegate(this);
                newCell->setPosition(Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + lastCell->getY() * slotSizeHeight));
                this->addChild(newCell, 0);
                items.at(column)->replace(lastCell->getY(), newCell);
                
                lastCell->removeFromParent();
            }
            
            for(int i = 0; i < shouldDeleteCountInColumn; ++i)
            {
                int bottle = arc4random()%4;
                CellStacked *newCell = (CellStacked *)Cell::create(column, slotsHeight - shouldDeleteCountInColumn + i + 1, (CellType)bottle);
                newCell->setDelegate(this);
                newCell->setPosition(Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + (slotsHeight + i) * slotSizeHeight));
                this->addChild(newCell, 0);
                items.at(column)->pushBack(newCell);
            }
        }

        
        // erase and move slots
        for(int column = 0; column < slotsWidth; ++column)
        {
            int i = 0;
            Vector<Cell *> *line = items.at(column);
            
            for (Vector<Cell *>::iterator iter = line->begin(); iter != line->end();)
            {
                Cell *cell = *iter;
                
                if(cell->getShouldDelete())
                {
                    log("delete cell %d %d",cell->getX(),cell->getY());
                    cell->removeFromParent();
                    iter = line->erase(iter);
                }
                else
                {
                    if(i != cell->getY())
                    {
                        auto action = JumpTo::create(0.35f,  Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + i * slotSizeHeight), 0.0f, 1);
                        
                        auto action2 = JumpTo::create(0.35f, Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + i * slotSizeHeight), 20.0f, 1);
                        
                        
                        Sequence *sequence = Sequence::createWithTwoActions(action, action2);
                        
                        
                        
                        //Action *action = MoveTo::create(0.3f, Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + i * slotSizeHeight));
                        cell->runAction(sequence);
                        cell->setY(i);
                    }
                    
                    ++iter;
                    ++i;
                }
            }
        }
    }
    
    //log("AHT");
    for(int column = 0; column < slotsWidth; ++column)
    {
        for(Cell *cell : *items.at(column))
        {
            //log("x=%d y=%d",cell->getX(),cell->getY());
        }
        //log("\n");
    }
    /*
    return;
    for(int column = 0; column < slotsWidth; ++column)
    {
        int emptySpaceCount = 0;
        bool turnOnSequence = false;
        int sumEmptySpaces = 0;
        
        for(int row = 0; row < items.at(column)->size(); ++row)
        {
            Cell *cell = items.at(column)->at(row);
            
            if(!cell->getShouldDelete())// || row == slotsHeight - 1)
            {
                if(emptySpaceCount)
                {
                    if(!turnOnSequence)
                    {
                        
                        for(int i = row - emptySpaceCount; i < row; ++i)
                        {
                            log("remove at %d %d",i, column);
                            
                            Cell *cellForRemove = items.at(column)->at(i);
                            cellForRemove->removeFromParent();
  
                        }
                        
                        turnOnSequence = true;
                    }
                    if(turnOnSequence)
                    {
                        Cell *cellForMove = items.at(column)->at(row);
                        cellForMove->setX(column);
                        cellForMove->setY(row - emptySpaceCount - sumEmptySpaces);
                        
                        Action *action = MoveTo::create(0.3f, Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + (row - emptySpaceCount - sumEmptySpaces) * slotSizeHeight));
                        cellForMove->runAction(action);
                        items.at(column)->replace(row - emptySpaceCount - sumEmptySpaces, cellForMove);
                        
                        log("move %d to %d %d %d",cellForMove->getType() , row - emptySpaceCount, column, cellForMove->getShouldDelete());
                    }
                }
            }
            else
            {
                if(turnOnSequence)
                {
                    turnOnSequence = false;
                    sumEmptySpaces += emptySpaceCount;
                    emptySpaceCount = 0;
                }
                ++emptySpaceCount;
                
            }
        }
    }
    
    for(int column = 0; column < slotsWidth; ++column)
    {
        for(int row = (int)items.at(column)->size() - 1; row >= slotsHeight ; --row)
        {
            log("delete at row =%d column = %d",row,column);
            items.at(column)->erase(row);
        }
    }
    */
    //Action *action = JumpTo::create(
    for(auto cell : itemsSnake)
    {
        ((CellStacked *)cell)->setState(Normal);
    }
    itemsSnake.clear();
}


