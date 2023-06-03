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
        enum Dir {Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4};
        Pacman(QWidget *parnet = nullptr);
        void move();
        Dir dir;
        //void eat_ball();
    private:
        QLabel *label;
        QPixmap pixmap;
        int x, y;
};

#endif // PACMAN_H
