#include "pacman.h"
#include <iostream>

Pacman::Pacman(QWidget *parent,Cell *cell) : GameObject(parent, cell)
{
    pic[0] = QPixmap(":/images/pacman/right.png");
    pic[1] = QPixmap(":/images/pacman/left.png");
    pic[2] = QPixmap(":/images/pacman/up.png");
    pic[3] = QPixmap(":/images/pacman/down.png");
}

void Pacman::move()
{
    this->cell->makeItEmpty(this->parent);
    this->cell->hasBall=false;
    this->cell=nextCell;
    QPixmap pixmap = GameObject::move();
    this->cell->putPacman(this->parent, pixmap);
}
