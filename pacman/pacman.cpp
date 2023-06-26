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
    QPixmap pixmap = GameObject::move();
    this->cell->put_pacman(this->parent, pixmap);
}
