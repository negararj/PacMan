#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamepanel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    GamePanel* panel = new GamePanel(this);
    this->setFixedSize(500,500);
    this->setCentralWidget(panel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

