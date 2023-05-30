#include "gamepanel.h"
#include <iostream>

GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    this->setFocusPolicy(Qt::StrongFocus);
}
