#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QLabel>
#include <QLayout>
#include "cell.h"
#include "gameobject.h"

class Ghost : public GameObject
{
    public:

        Color color;
        Ghost(QWidget *parent,Cell *cell, Color color);
        void move(GameState gamestate);
};

#endif // GHOST_H
