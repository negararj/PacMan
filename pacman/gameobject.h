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
    Right, Left, Up, Down
};
enum GameState{win, lose, pmode, running};
class GameObject
{

    public:
        QPixmap pic[5];
        GameObject(QWidget *parent,Cell *cell);
        void setNextDir(Direction direction);
        void setNextCell();
        Cell* findNextCell(Direction direction);
        QPixmap move();

        QWidget *parent;
        Cell *cell, *nextCell, *initCell;
        Direction nextDir, currentDir;
};

#endif // GameObject_H
