#include "pacman.h"
#include <iostream>
Pacman::Pacman(QWidget *parent,Cell *cell){
    this->cell = cell;
    this->parent=parent;
    this->nextCell=this->cell;
}
void Pacman::setNextCell(Direction direction){
    this->nextDir=direction;
}
void Pacman::move()
{



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
        return;
    }

    this->cell->make_it_empty(this->parent);
    this->cell = nextCell;
    this->cell->put_pacman(this->parent);
}
