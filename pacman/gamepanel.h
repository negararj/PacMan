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

#include "pacman.h"

class GamePanel : public QWidget
{
    Q_OBJECT
    public:
        explicit GamePanel(QWidget *parent = nullptr);
        void keyPressEvent(QKeyEvent *event) override;
    private:
        Pacman* pacman;
};

#endif // GAMEPANEL_H
