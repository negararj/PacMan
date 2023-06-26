#include "gameobject.h"
#include <iostream>
GameObject::GameObject(QWidget *parent,Cell *cell){
    this->cell = cell;
    this->parent=parent;
    this->nextCell=this->cell;
    this->currentDir = this->nextDir = Null;
}
void GameObject::setNextDir(Direction direction){
    this->nextDir=direction;
}
void GameObject::setNextCell(){
    switch(nextDir){
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

    if(nextCell->state == CellState::wall){
        switch(currentDir){
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
        case Null:
            return;
        }
        if(nextCell->state == CellState::wall)
            return;
    }
    else{
        currentDir = nextDir;
    }
}
QPixmap GameObject::move()
{
  //  this->cell->make_it_empty(this->parent);
    this->cell = nextCell;
    QPixmap pixmap;

    switch (currentDir) {
    case Right:
        pixmap = pic[0];
        break;
    case Left:
        pixmap = pic[1];
        break;
    case Up:
        pixmap = pic[2];
        break;
    case Down:
        pixmap = pic[3];
        break;
    case Null:
        pixmap = pic[0];
        break;
    }
    return pixmap;
}
