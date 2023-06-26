#include "pacman.h"
#include <iostream>
Pacman::Pacman(QWidget *parent,Cell *cell){
    this->cell = cell;
    this->parent=parent;
    this->nextCell=this->cell;
    this->currentDir = Null;
}
void Pacman::setNextDir(Direction direction){
    this->nextDir=direction;
}
void Pacman::setNextCell(){
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
void Pacman::move()
{
    this->cell->make_it_empty(this->parent);
    this->cell = nextCell;
    QPixmap pixmap;

    switch (currentDir) {
        case Right:
            pixmap = QPixmap(":/images/pacman/right.png");
            break;
        case Left:
            pixmap = QPixmap(":/images/pacman/left.png");
            break;
        case Up:
            pixmap = QPixmap(":/images/pacman/up.png");
            break;
        case Down:
            pixmap = QPixmap(":/images/pacman/down.png");
            break;
        case Null:
            pixmap = QPixmap(":/images/pacman/right.png");
            break;
    }
    this->cell->put_pacman(this->parent, pixmap);

}
