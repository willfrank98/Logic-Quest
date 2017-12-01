#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDesktopWidget>
#include <sceneholder.h>
#include <Box2D.h>
#include <SFML/Audio.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void swapScene(QString s);
    void hookupScene();
    SceneHolder *scenes = new SceneHolder();
};

#endif // MAINWINDOW_H
