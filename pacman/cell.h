#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>

enum CellState{
   pacman , ghost, wall, empty, ball
};


class Cell : public QWidget
{

public:
    Cell(QWidget *parent, int x, int y, Cell *left =nullptr, Cell *up=nullptr);
    CellState state;
    Cell* left;
    Cell* right;
    Cell* up;
    Cell* down;
    int x;
    int y;
    void put_pic(QPixmap pixmap);
    void make_it_empty(QWidget *parent);
    void put_pacman(QWidget *parent, QPixmap pixmap);
    void put_wall(QWidget *parent);
    void put_ball(QWidget *parent);
    QLabel *label;
};

#endif // CELL_H
