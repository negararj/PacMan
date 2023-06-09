#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QLabel>
#include <QLayout>
#include "cell.h"
#include "gameobject.h"


class Pacman : public GameObject
{
    public:
        Pacman(QWidget *parent,Cell *cell);
        void move();
};

#endif // PACMAN_H
