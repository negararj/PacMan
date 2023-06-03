#include "pacman.h"

Pacman::Pacman(QWidget *parent) : QWidget(parent) {
    label = new QLabel(parent);
    pixmap = QPixmap(":/images/a4.png");
    label->setPixmap(pixmap);
    x = 1; y = 1;
    resize(pixmap.width(), pixmap.height());
    label->setGeometry(x, y, pixmap.width(), pixmap.height());
}

void Pacman::move(){
    x += 10;
    label->setGeometry(x,y,pixmap.width(),pixmap.height());
}

