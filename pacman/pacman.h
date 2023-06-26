#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QLabel>
#include <QLayout>
#include "cell.h"

enum Direction{
    Up, Down, Left, Right, Null
};

class Pacman
{
    public:
        Pacman(QWidget *parent,Cell *cell);

        void setNextDir(Direction direction);
        void setNextCell();
        void move();

        QWidget *parent;
        Cell *cell, *nextCell;
        Direction nextDir, currentDir;
};

#endif // PACMAN_H
