/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * spriteloader.h
 */

#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <QPixmap>
#include <QMap>

class SpriteLoader
{
public:
    SpriteLoader();
    QPixmap getSprite(QString sheetName, QSize frameSize, int frame);
    QList<QPixmap> getGates();
    QList<QString> getGateNames();

private:
    QMap<QString, QPixmap> sprites;

};

#endif // SPRITELOADER_H
