#include "pacman.h"
#include <iostream>
Pacman::Pacman(Cell *cell){
    this->cell = cell;
}

void Pacman::move(Direction direction, QWidget *parent)
{
    this->cell->make_it_empty(parent);
    std::cout<<"ba"<<std::endl;
    switch(direction){
        case Up:
            this->cell = this->cell->up;
            break;
        case Down:
            this->cell = this->cell->down;
            break;
        case Left:
            this->cell = this->cell->left;
            break;
        case Right:
            this->cell = this->cell->right;
            break;
    }

    this->cell->put_pacman(parent);
}
