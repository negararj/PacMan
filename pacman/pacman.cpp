#include "pacman.h"
#include <iostream>
Pacman::Pacman(Cell *cell){
    this->cell = cell;
}

void Pacman::move(Direction direction, QWidget *parent)
{
    Cell *next_cell = nullptr;
    switch(direction){
    case Up:
        next_cell = this->cell->up;
        break;
    case Down:
        next_cell = this->cell->down;
        break;
    case Left:
        next_cell = this->cell->left;
        break;
    case Right:
        next_cell = this->cell->right;
        break;
    }
    if(next_cell->state == CellState::wall){
        std::cout << "ghar" << std::endl;
        return;
    }
    this->cell->make_it_empty(parent);
    this->cell = next_cell;
    this->cell->put_pacman(parent);
}
