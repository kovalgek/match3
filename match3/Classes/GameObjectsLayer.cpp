//
//  GameObjectsLayer.cpp
//  QuestGame
//
//  Created by Антон Ковальчук on 10.03.14.
//
//

#include "GameObjectsLayer.h"
#include "Cell.h"

/*
#include "Hero.h"
#include "RootScene.h"
#include "UserInterfaceLayer.h"
#include "Inventory.h"
#include "InventoryObject.h"
#include "BackgroundLayer.h"
*/
USING_NS_CC;

int GameObjectsLayer::slotsWidth  = 6;
int GameObjectsLayer::slotsHeight = 7;
int GameObjectsLayer::slotShiftLeft = 60;
int GameObjectsLayer::slotShiftBottom = 60;
int GameObjectsLayer::slotSizeWidth = 105.0f;
int GameObjectsLayer::slotSizeHeight = 111.0f;

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
            Cell *cell = Cell::create(column, row);
            cell->setDelegate(this);
            cell->setPosition(Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + row * slotSizeHeight));
            //cell->getMainImage()->setPosition(Point(100 + 90.0f * column, 100 + row * 90.0f));
            this->addChild(cell, 0);
            line->pushBack(cell);
        }
        items.push_back(line);
    }
    
    return true;
}

void GameObjectsLayer::activateSnake(Cell *cell)
{
    itemsSnake.pushBack(cell);
}

void GameObjectsLayer::searchCells(Point point)
{
    for(int column = 0; column < slotsWidth; ++column)
    {
        Vector<Cell *> *line = items.at(column);
        
        for(int row = 0; row < slotsHeight; ++row)
        {
            Cell *cell = line->at(row);
        
            Size size = cell->getMainImage()->getContentSize();
            Rect rect = Rect(cell->getPosition().x - size.width * 0.5f, cell->getPosition().y - size.height * 0.5f, size.width, size.height);

            if (rect.containsPoint(point) && itemsSnake.back()->getType() == cell->getType())
            {
                if(cell->getState() == Normal)
                {
                    if(abs(itemsSnake.back()->getX() - cell->getX()) <= 1 &&
                       abs(itemsSnake.back()->getY() - cell->getY()) <= 1)
                    {
                        cell->setShouldDelete(true);
                        cell->setState(Activated);
                        itemsSnake.pushBack(cell);
                    }
                }
                else if(cell->getState() == Activated)
                {
                    int index = (int)itemsSnake.getIndex(cell);
                    
                    if(index >= 0 && index <= itemsSnake.size() - 1)
                    {
                        Vector<Cell *>::iterator iter;
                        
                        for(int i = (int)itemsSnake.size() - 1; i > index; --i)
                        {
                            cell->setShouldDelete(false);
                            itemsSnake.at(i)->setState(Normal);
                            itemsSnake.erase(i);
                        }
                    }
                }
            }
        }
    }
}

void GameObjectsLayer::closeSnake()
{
    for(int column = 0; column < slotsWidth; ++column)
    {
        int shouldDeleteCountInColumn = 0;
        for(int row = 0; row < slotsHeight; ++row)
        {
            Cell *cell = items.at(column)->at(row);
            if(cell->getShouldDelete())
            {
                log("cel should delete=%d %d",cell->getX(),cell->getY());
                ++shouldDeleteCountInColumn;
            }
        }
        log("shouldDeleteCountInColumn=%d",shouldDeleteCountInColumn);
        for(int i = 0; i < shouldDeleteCountInColumn; ++i)
        {
            Cell *newCell = Cell::create(column, slotsHeight - shouldDeleteCountInColumn + i);
            newCell->setDelegate(this);
            newCell->setPosition(Point(slotShiftLeft + slotSizeWidth * column, slotShiftBottom + (slotsHeight + i) * slotSizeHeight));
            this->addChild(newCell, 0);
            items.at(column)->pushBack(newCell);
            
            log("newCell= %d %d",newCell->getX(),newCell->getY());
        }
    }
    //return;
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
    
    //Action *action = JumpTo::create(
    for(auto cell : itemsSnake)
    {
        cell->setState(Normal);
    }
    itemsSnake.clear();
}


