#include "pacman.h"

Pacman::Pacman(QWidget *parent) : QWidget(parent) {
    label = new QLabel(parent);
    pixmap = QPixmap(":/images/a4.png");
    label->setPixmap(pixmap);
    cell = new Cell(1, 1);
    resize(pixmap.width(), pixmap.height());
    label->setGeometry(this->cell->x, this->cell->y, pixmap.width(), pixmap.height());
}

void Pacman::move(Dir dir){
    switch(dir){
    case Left:
        this->cell = this->cell->left;
    case Right:
        this->cell = this->cell->right;
    case Up:
        this->cell = this->cell->up;
    case Down:
        this->cell = this->cell->down;
    }
    label->setGeometry(this->cell->x, this->cell->y, pixmap.width(), pixmap.height());
}

