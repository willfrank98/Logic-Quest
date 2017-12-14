/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * main.cpp
 */


#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
