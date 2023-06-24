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
    Up, Down, Left, Right
};

class Pacman
{
    public:
        Pacman(Cell *cell);
        void move(Direction direction, QWidget *parent);
        Cell *cell;
};

#endif // PACMAN_H
