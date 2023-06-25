#include "gamepanel.h"

#include <iostream>
GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    this->setFocusPolicy(Qt::StrongFocus);
    make_the_map(parent);
   // this->parent=parent;

    this->movementThread = new std::thread ([this](){
        while(true){
            this->pacman->move();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
}

void GamePanel::make_the_map(QWidget *parent){

    QFile mapfile(":/images/map.txt");
    mapfile.open(QIODevice::ReadOnly|QIODevice::Text);

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
            switch(line[j]){
            case '0':
                map[i][j]->put_ball(parent);
                break;
            case '1':
                map[i][j]->put_wall(parent);
                break;
            case 'p':
                map[i][j]->put_pacman(parent);
                pacman = new Pacman(parent,map[i][j]);
                break;
            case '3':
                map[i][j]->make_it_empty(parent);
                break;
            }
        }
    }

}
void GamePanel::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_Left:
        pacman->setNextCell(Left);
        break;
    case Qt::Key_Right:
        pacman->setNextCell(Right);
        break;

    case Qt::Key_Up:
        pacman->setNextCell(Up);
        break;

    case Qt::Key_Down:
        pacman->setNextCell(Down);
        break;
    //case Qt::Key_1:
       // pacman->move();
    }
}
