#include "gamepanel.h"
#include <iostream>
#include <QWidget>

GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    Pacman pacman(parent);
}
