/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * mainwindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDesktopWidget>
#include <sceneholder.h>
#include <Box2D.h>
#include <SFML/Audio.hpp>
#include <QMediaPlayer>

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
	void changeResolution(QString s);
    void hookupScene();
    SceneHolder *scenes = new SceneHolder();
    QMediaPlayer* musicPlayer;
};

#endif // MAINWINDOW_H
