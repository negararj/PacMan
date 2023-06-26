#include "ghost.h"

Ghost::Ghost(QWidget *parent,Cell *cell, Color color) : GameObject(parent, cell)
{
    pic[4] = QPixmap(":/images/ghost/run.png");
    switch (color) {
    case green:
        pic[0] = QPixmap(":/images/ghost/green/right.png");
        pic[1] = QPixmap(":/images/ghost/green/left.png");
        pic[2] = QPixmap(":/images/ghost/green/up.png");
        pic[3] = QPixmap(":/images/ghost/green/down.png");
        break;
    case red:
        pic[0] = QPixmap(":/images/ghost/red/right.png");
        pic[1] = QPixmap(":/images/ghost/red/left.png");
        pic[2] = QPixmap(":/images/ghost/red/up.png");
        pic[3] = QPixmap(":/images/ghost/red/down.png");
        break;
    case pink:
        pic[0] = QPixmap(":/images/ghost/pink/right.png");
        pic[1] = QPixmap(":/images/ghost/pink/left.png");
        pic[2] = QPixmap(":/images/ghost/pink/up.png");
        pic[3] = QPixmap(":/images/ghost/pink/down.png");
        break;
    case orange:
        pic[0] = QPixmap(":/images/ghost/orange/right.png");
        pic[1] = QPixmap(":/images/ghost/orange/left.png");
        pic[2] = QPixmap(":/images/ghost/orange/up.png");
        pic[3] = QPixmap(":/images/ghost/orange/down.png");
        break;
    }
    this->color=color;
    this->cell->putGhost(parent, pic[0],(int)color);
    this->cell->id=(int)color;
}

void Ghost::move(GameState gamestate)
{
    if(this->cell->hasBall){
        this->cell->putBall(this->parent);
    }else{
        this->cell->makeItEmpty(this->parent);
    }
    this->cell = nextCell;
    QPixmap pixmap;
    if(gamestate == running){
        pixmap = GameObject::move();
    }else{
        pixmap = this->pic[4];
    }
    this->cell->putGhost(this->parent, pixmap, this->cell->id);
}
