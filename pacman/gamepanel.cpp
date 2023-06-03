#include "gamepanel.h"

GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    this->setFocusPolicy(Qt::StrongFocus);
    pacman = new Pacman(parent);
}

void GamePanel::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        pacman->move();
        break;
    case Qt::Key_Right:
        pacman->move();
        break;

    case Qt::Key_Up:
        pacman->move();
        break;

    case Qt::Key_Down:
        pacman->move();
        break;
    }
}
