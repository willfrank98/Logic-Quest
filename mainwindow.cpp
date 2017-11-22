#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b2Vec2 gravity = b2Vec2(0.0, 9.8);
    b2World world(gravity);
}

MainWindow::~MainWindow()
{
    delete ui;
}
