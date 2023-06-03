#include "pacman.h"
#include <iostream>

Pacman::Pacman(QWidget *parent) : QWidget(parent) {
    QLabel *label = new QLabel(parent);
    QPixmap pixmap(":/images/a4.png");
    label->setPixmap(pixmap);

    resize(pixmap.width(), pixmap.height());
}

