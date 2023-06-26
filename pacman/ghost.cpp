#include "ghost.h"

Ghost::Ghost(QWidget *parent,Cell *cell, Color color) : GameObject(parent, cell)
{
    pic[4] = QPixmap(":/images/ghost/run.png");
    switch (color) {
    case green:
        pic[0] = QPixmap(":/images/ghost/green/right.png");
        pic[1] = QPixmap(":/images/ghost/green/left.png");
        pic[2] = QPixmap(":/images/ghost/green/up.png");
        pic[3] = QPixmap(":/images/ghost/green/down.png");
        break;
    case red:
        pic[0] = QPixmap(":/images/ghost/red/right.png");
        pic[1] = QPixmap(":/images/ghost/red/left.png");
        pic[2] = QPixmap(":/images/ghost/red/up.png");
        pic[3] = QPixmap(":/images/ghost/red/down.png");
        break;
    case pink:
        pic[0] = QPixmap(":/images/ghost/pink/right.png");
        pic[1] = QPixmap(":/images/ghost/pink/left.png");
        pic[2] = QPixmap(":/images/ghost/pink/up.png");
        pic[3] = QPixmap(":/images/ghost/pink/down.png");
        break;
    case orange:
        pic[0] = QPixmap(":/images/ghost/orange/right.png");
        pic[1] = QPixmap(":/images/ghost/orange/left.png");
        pic[2] = QPixmap(":/images/ghost/orange/up.png");
        pic[3] = QPixmap(":/images/ghost/orange/down.png");
        break;
    }
}

void Ghost::move()
{
    QPixmap pixmap = GameObject::move();
    this->cell->put_ghost(this->parent, pixmap);
}
