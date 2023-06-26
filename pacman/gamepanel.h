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

#include "pacman.h"
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
        int score;
        int ball_numbers;
        QWidget *parent;

        Cell* map[rows][columns];
        GameState state;
        QLabel *score_title, *scoreLabel;
        QLabel *win_label, *lose_label;
        QTimer *score_timer;

        std::thread *movementThread;

        friend void Cell::make_it_empty(QWidget *p);

};

#endif // GAMEPANEL_H
