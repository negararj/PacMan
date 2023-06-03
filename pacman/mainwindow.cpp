#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    GamePanel* panel = new GamePanel(this);
    this->setFixedSize(800,500);
    this->setCentralWidget(panel);
    this->setStyleSheet("background-color: black");
}

MainWindow::~MainWindow()
{
    delete ui;
}

