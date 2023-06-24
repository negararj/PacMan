#include "cell.h"
#include <QLabel>
#include <QPixmap>

Cell::Cell(QWidget *parent, int x, int y, Cell *left = NULL, Cell *up = NULL) : QWidget(parent)
{
    this->x = x;
    this->y = y;
    state = Empty;
    this->up = up;
    this->left = left;
    if(up != NULL)
        up->down = this;
    if(right != NULL)
        left->right = this;

    label = new QLabel(parent);

    this->make_it_empty(parent);
}

void Cell::put_pic(QPixmap pixmap){
    label->setPixmap(pixmap);
    resize(pixmap.width(), pixmap.height());
    label->setGeometry(this->x, this->y, pixmap.width(), pixmap.height());
    this->state = Pacman;
}

void Cell::make_it_empty(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/empty.png");
    put_pic(pixmap);
}

void Cell::put_pacman(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/a4.png");
    put_pic(pixmap);
}

void Cell::put_wall(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/wall.png");
    put_pic(pixmap);
}

void Cell::put_ball(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/ball.png");
    put_pic(pixmap);
}


