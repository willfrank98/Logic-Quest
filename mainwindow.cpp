/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * mainwindow.cpp
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "Box2D.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Logic Quest");

    // Set the initial scene to the title scene
    ui->graphicsView->setScene(scenes->getScene("Title"));
    ui->graphicsView->installEventFilter(ui->graphicsView->scene());
    this->setStyleSheet("background-color: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 lightblue, stop:1 black);");

    // Connects the menubar actions.
    connect(ui->actionExit, &QAction::triggered, this, [=](){ QApplication::quit(); });
    connect(ui->actionMain_Menu, &QAction::triggered, this, [=](){swapScene("title");});

    // Hookup some connections to the scene
    hookupScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Used for scene swapping
void MainWindow::swapScene(QString s)
{
    qDebug() << "[INFO]" << "Scene changing to:" << s.replace("\"", "");
    delete ui->graphicsView->scene();
    ui->graphicsView->hide();
    ui->graphicsView->setScene(scenes->getScene(s));
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->installEventFilter(ui->graphicsView->scene());
    ui->graphicsView->show();

    // Reconnect things
    hookupScene();
    qDebug() << "[INFO]" << "Scene changed to:" << s.replace("\"", "");
}

// (Re)connects to some signals from a scene.
void MainWindow::hookupScene()
{
    connect((BasicScene*)ui->graphicsView->scene(), &BasicScene::changeScene, this, &MainWindow::swapScene);
    connect((PhysicsScene*)ui->graphicsView->scene(), &PhysicsScene::endProgram, this, [=](){ QApplication::quit(); });
}
