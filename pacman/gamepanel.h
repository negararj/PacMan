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
#include <QTimer>

#include "gameobject.h"
#include "pacman.h"
#include "ghost.h"
#include "cell.h"

const int rows = 20, columns = 29;

class GamePanel : public QWidget
{
    Q_OBJECT
    public:
        enum GameState{win, lose, pause, running};

        explicit GamePanel(QWidget *parent = nullptr);
        void keyPressEvent(QKeyEvent *event) override;
        void make_the_map(QWidget *parent = nullptr);
        void init_labels();
        void update_score();

    private:
        Pacman* pacman;
        Ghost *ghosts[4];
        int score;
        int ball_numbers, powerball_numbers;
        Cell* map[rows][columns];
        GameState state;
        QWidget *parent;
        QLabel *score_title, *scoreLabel;
        QLabel *win_label, *lose_label;
        QTimer *score_timer;
        std::thread *movementThread,*ghostsMovement;
};

#endif // GAMEPANEL_H
