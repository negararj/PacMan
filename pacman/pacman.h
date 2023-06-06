#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QLabel>
#include <QLayout>
#include "cell.h"

class Pacman : public QWidget
{
    public:
        enum Dir {Up, Down, Left, Right};
        Pacman(QWidget *parnet = nullptr);
        void move(Dir dir);
        void eat_ball(int *score);

    private:
        QLabel *label;
        QPixmap pixmap;
        Cell *cell;
};

#endif // PACMAN_H
