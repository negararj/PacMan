#include "gamepanel.h"

GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    this->setFocusPolicy(Qt::StrongFocus);
    pacman = new Pacman();
}

void GamePanel::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        pacman->move(Left);
        break;
    case Qt::Key_Right:
        pacman->move(Right);
        break;

    case Qt::Key_Up:
        pacman->move(Up);
        break;

    case Qt::Key_Down:
        pacman->move(Down);
        break;
    }
}
