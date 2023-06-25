#include "cell.h"
#include <QLabel>
#include <QPixmap>
#include <iostream>
Cell::Cell(QWidget *parent, int x, int y, Cell *left, Cell *up) : QWidget(parent)
{
    this->x = x;
    this->y = y;
    state = empty;
    this->up = up;
    this->left = left;
    if(up != nullptr)
        up->down = this;
    if(left != nullptr)
        left->right = this;
    label = new QLabel(parent);
    this->make_it_empty(parent);
}

void Cell::put_pic(QPixmap pixmap){
    label->setPixmap(pixmap);
    resize(pixmap.width(), pixmap.height());
    label->setGeometry(this->x, this->y, pixmap.width(), pixmap.height());
}

void Cell::make_it_empty(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/empty.png");
    put_pic(pixmap);
    this->state = empty;
}

void Cell::put_pacman(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/a4.png");
    put_pic(pixmap);
    this->state = pacman;
}

void Cell::put_wall(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/wall.png");
    put_pic(pixmap);
    this->state = wall;
}

void Cell::put_ball(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/ball.png");
    put_pic(pixmap);
    this->state = ball;
}


