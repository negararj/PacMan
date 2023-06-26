#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>

enum CellState{
    pacman , ghost, wall, empty, ball, powerBall
};

enum Color{
    green, red, pink, orange
};

class Cell : public QWidget
{
    public:
        Cell(QWidget *parent, int x, int y, Cell *left =nullptr, Cell *up=nullptr);
        void putPic(QPixmap pixmap);
        void makeItEmpty(QWidget *parent);
        void putPacman(QWidget *parent, QPixmap pixmap);
        void putWall(QWidget *parent);
        void putBall(QWidget *parent);
        void putPowerball(QWidget *parent);
        void putGhost(QWidget *parent, QPixmap pixmap);

        CellState state;
        bool hasBall;
        Cell* left;
        Cell* right;
        Cell* up;
        Cell* down;
        int x;
        int y;
        QLabel *label;
};

#endif // CELL_H
