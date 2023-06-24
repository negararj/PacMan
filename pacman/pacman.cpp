#include "pacman.h"

Pacman::Pacman(Cell *cell){
    this->cell = cell;
}

void Pacman::move(Direction direction, QWidget *parent)
{
    this->cell->make_it_empty(parent);

    switch(direction){
        case Up:
            this->cell = this->cell->up;
        case Down:
            this->cell = this->cell->down;
        case Left:
            this->cell = this->cell->left;
        case Right:
            this->cell = this->cell->right;
    }

    this->cell->put_pacman(parent);
}
