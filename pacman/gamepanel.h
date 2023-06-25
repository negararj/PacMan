#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QColor>
#include <QKeyEvent>
#include <thread>
#include <chrono>
#include <iostream>
#include <QFile>

#include "pacman.h"
#include "cell.h"

const int rows = 500, columns = 500;

class GamePanel : public QWidget
{
    Q_OBJECT
    public:
        enum GameState{win, loose, pause, running};

        explicit GamePanel(QWidget *parent = nullptr);

        void keyPressEvent(QKeyEvent *event) override;
        void make_the_map(QWidget *parent = nullptr);

    private:
        Pacman* pacman;
        int score;
        int ball_numbers;
        QWidget *parent;

        Cell* map[rows][columns];
        GameState state;

};

#endif // GAMEPANEL_H
