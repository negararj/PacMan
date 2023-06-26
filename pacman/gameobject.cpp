#include "gameobject.h"
#include <iostream>

GameObject::GameObject(QWidget *parent, Cell *cell){
    this->parent = parent;
    this->initCell = this->nextCell = this->cell = cell;
    this->currentDir = this->nextDir = Up;
}
void GameObject::setNextDir(Direction direction){
    this->nextDir=direction;
}
Cell* GameObject::findNextCell(Direction direction){
    Cell *nextCell;
    switch(direction){
    case Up:
        nextCell = this->cell->up;
        break;
    case Down:
        nextCell = this->cell->down;
        break;
    case Left:
        nextCell = this->cell->left;
        break;
    case Right:
        nextCell = this->cell->right;
        break;
    }
    return nextCell;
}
void GameObject::setNextCell(){
    nextCell = findNextCell(nextDir);

    if(nextCell->state == CellState::wall){
        nextCell = findNextCell(currentDir);
        if(nextCell->state == CellState::wall)
            return;
    }
    else{
        currentDir = nextDir;
    }
}
QPixmap GameObject::move()
{


    QPixmap pixmap = pic[Direction(currentDir)];
    return pixmap;
}
