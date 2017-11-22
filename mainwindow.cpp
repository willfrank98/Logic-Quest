#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "Box2D.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Simple Box2D check
    b2Vec2 gravity = b2Vec2(0.0, 9.8);
    b2World world(gravity);

    // Simple SFML check
    sf::SoundBuffer sbuf;

}

MainWindow::~MainWindow()
{
    delete ui;
}
