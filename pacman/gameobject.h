#ifndef GameObject_H
#define GameObject_H

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

class GameObject
{
    protected:
        QPixmap pic[5];
    public:
        GameObject(QWidget *parent,Cell *cell);

        void setNextDir(Direction direction);
        void setNextCell();
        QPixmap move();

        QWidget *parent;
        Cell *cell, *nextCell;
        Direction nextDir, currentDir;
};

#endif // GameObject_H
