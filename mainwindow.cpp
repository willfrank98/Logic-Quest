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

    // Set the initial scene to the title scene
    ui->graphicsView->setScene(scenes->getScene("Title"));
    ui->graphicsView->installEventFilter(ui->graphicsView->scene());

    // Only allow one resolution option to be selected
    QActionGroup *resSettings = new QActionGroup(nullptr);
    for (QAction *action : ui->menuResolution->actions())
    {
        action->setActionGroup(resSettings);
    }

    // Handles resolution changes
    connect(resSettings, &QActionGroup::triggered, this, [=](QAction *a){

        // Gets the width and height from the action name
        QString newRes = a->text();
        int width = newRes.split('x').first().toInt();
        int height = newRes.split('x').last().toInt();

        // Just make fullscreen if unable to parse correctly
        if (width == 0 && height == 0)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else  // Resize things to the desired dimensions
        {
            setWindowState(Qt::WindowNoState);
            resize(width, height);
            setGeometry(QApplication::desktop()->size().width() / 2.0 - size().width() / 2.0,
                        QApplication::desktop()->size().height() / 2.0 - size().height() / 2.0,
                        size().width(), size().height());
        }
    });

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
