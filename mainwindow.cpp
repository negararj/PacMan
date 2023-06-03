#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    /*
    GamePanel* panel = new GamePanel(this);
    this->setFixedSize(500,500);
    this->setCentralWidget(panel);
    this->setStyleSheet("background-color: black");
    */
    // Load the Pacman image
    QPixmap pixmap(":/a4.png");

    // Scale the image and set it as the pixmap for the Pacman object
    pixmap = pixmap.scaledToHeight(50);
    setPixmap(pixmap);

    // Create a new QGraphicsScene and add a QGraphicsPixmapItem to it
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(":/a4.png"));
    scene->addItem(item);

    // Create a new QGraphicsView and set its scene to the one we just created
    QGraphicsView* view = new QGraphicsView(scene);

    // Show the view
    view->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

