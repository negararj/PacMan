#include "gamepanel.h"
#include <iostream>
#include <random>

const int SCORE = 10;

GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    srand (time(NULL));
    this->setFocusPolicy(Qt::StrongFocus);
    score = 0;
    ball_numbers = 0;
    make_the_map(parent);
    state = GameState::running;

    init_labels();

    //this->parent=parent;

    this->movementThread = new std::thread ([this](){

        while(this->state == running){
            this->pacman->setNextCell();

            if(this->pacman->nextCell->state == ghost){
                this->state=lose;
                update_score();
            }

            if(pacman->nextCell != pacman->cell && pacman->nextCell->state == ball){
                //std::cout << "ghar" << std::endl;
                score += SCORE;
                update_score();
            }

            if(pacman->nextCell->state != wall){
                this->pacman->move();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

    });

    this->ghostsMovement = new std::thread([this](){

        while(this->state == running ){
            for(int i=0;i<4;i++){
                ghosts[i]->setNextDir(Direction(random()%4));
                this->ghosts[i]->setNextCell();

                if(this->ghosts[i]->nextCell->state == CellState::pacman){
                    this->state=lose;
                    update_score();
                }

                if(ghosts[i]->nextCell->state != wall){
                    this->ghosts[i]->move();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }

    });
}

void GamePanel::update_score(){
    scoreLabel->setText(QString::number(score));
    if(score == ball_numbers * SCORE){
        state = win;
    }
    if (state == win) {
        win_label->show();
        //score_timer->stop();
    }else if (state == lose) {
        lose_label->show();
        //score_timer->stop();
    }
}

void GamePanel::init_labels(){
    score_title = new QLabel(this);
    score_title->setText("score");
    score_title->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    score_title->setGeometry(50, 12, 60, 26);

    scoreLabel = new QLabel(this);
    scoreLabel->setIndent(-80);
    scoreLabel->setText("0");
    scoreLabel->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    scoreLabel->setGeometry(110, 12, 150, 26);

    win_label = new QLabel(this);
    win_label->hide();
    win_label->setText("You win!");
    win_label->setStyleSheet("QLabel {font-family: Fixedsys;color: yellow;font-size: 16px;}");
    win_label->setGeometry(310, 12, 150, 26);

    lose_label = new QLabel(this);
    lose_label->hide();
    lose_label->setText("You lose!");
    lose_label->setStyleSheet("QLabel {font-family: Fixedsys;color: red;font-size: 16px;}");
    lose_label->setGeometry(310, 12, 150, 26);

    update_score();
}

void GamePanel::make_the_map(QWidget *parent){

    QFile mapfile(":/images/map.txt");
    mapfile.open(QIODevice::ReadOnly|QIODevice::Text);

    int ghostCounter = 0;

    for(int i=0;i<rows;i++){
        QByteArray line = mapfile.readLine();
        for(int j=0;j<columns;j++){
           if(i>0){
                if(j>0){
                   map[i][j] = new Cell(parent,50+(20*j),50+(20*i),map[i][j-1],map[i-1][j]);
                }else{
                    map[i][j] = new Cell(parent,50+(20*j),50+(20*i),nullptr,map[i-1][j]);
                }
            }else{
                if(j>0){
                    map[i][j] = new Cell(parent,50+(20*j),50+(20*i),map[i][j-1]);
                }else{
                    map[i][j] = new Cell(parent,50+(20*j),50+(20*i));
                }
            }
            QPixmap pix;
            switch(line[j]){
            case '0':
                map[i][j]->put_ball(parent);
                ball_numbers ++;
                break;
            case '1':
                map[i][j]->put_wall(parent);
                break;
            case 'p':
                pix = QPixmap(":/images/pacman/right.png");
                map[i][j]->put_pacman(parent, pix);
                pacman = new Pacman(parent,map[i][j]);
                break;
            case '3':
                map[i][j]->make_it_empty(parent);
                break;
            case 'g':
                if(ghostCounter == 0){
                    pix = QPixmap(":/images/ghost/green/right.png");
                }
                else if(ghostCounter == 1){
                    pix = QPixmap(":/images/ghost/red/right.png");
                }
                else if(ghostCounter == 2){
                    pix = QPixmap(":/images/ghost/pink/right.png");
                }
                else{
                    pix = QPixmap(":/images/ghost/orange/right.png");
                }
                map[i][j]->put_ghost(parent, pix);
                ghosts[ghostCounter] = new Ghost(parent, map[i][j], Color(ghostCounter));
                ghostCounter ++;
            }
        }
    }
}
void GamePanel::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        pacman->setNextDir(Left);
        break;
    case Qt::Key_Right:
        pacman->setNextDir(Right);
        break;

    case Qt::Key_Up:
        pacman->setNextDir(Up);
        break;

    case Qt::Key_Down:
        pacman->setNextDir(Down);
        break;
    }
}
