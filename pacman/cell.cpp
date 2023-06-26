#include "cell.h"
#include <QLabel>
#include <QPixmap>
#include <iostream>
Cell::Cell(QWidget *parent, int x, int y, Cell *left, Cell *up) : QWidget(parent)
{
    this->x = x;
    this->y = y;
    this->up = up;
    this->left = left;
    state = empty;
    if(up != nullptr)
        up->down = this;
    if(left != nullptr)
        left->right = this;
    label = new QLabel(parent);
    this->makeItEmpty(parent);
    hasBall=false;
}

void Cell::putPic(QPixmap pixmap){
    label->setPixmap(pixmap);
    resize(pixmap.width(), pixmap.height());
    label->setGeometry(this->x, this->y, pixmap.width(), pixmap.height());
}

void Cell::makeItEmpty(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/empty.png");
    putPic(pixmap);
    this->state = empty;
}

void Cell::putPacman(QWidget *parent, QPixmap pixmap)
{
    putPic(pixmap);
    this->state = pacman;
}

void Cell::putWall(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/wall.png");
    putPic(pixmap);
    this->state = wall;
}

void Cell::putBall(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/ball.png");
    putPic(pixmap);
    this->state = ball;
    hasBall=true;
}

void Cell::putPowerball(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/power_ball.png");
    putPic(pixmap);
    this->state = powerBall;
    hasBall=true;
}

void Cell::putGhost(QWidget *parent, QPixmap pixmap ,int id)
{
    putPic(pixmap);
    this->state = ghost;
    this->id=id;
}


