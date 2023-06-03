#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QLabel>
#include <QLayout>

class Pacman : public QWidget
{
    public:
        Pacman(QWidget *parnet = nullptr);
        //void move();
        //void eat_ball();
};

#endif // PACMAN_H
