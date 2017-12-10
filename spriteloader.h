#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <QPixmap>
#include <QMap>

class SpriteLoader
{
public:
    SpriteLoader();
    QPixmap getSprite(QString sheetName, QSize frameSize, int frame);
    QList<QPixmap> getSprites(QString sheetName, QSize frameSize);

    // TODO: remove these two method to make SpriteLoader more of a tool
    QList<QPixmap> getGates();
    QList<QString> getGateNames();

private:
    QMap<QString, QPixmap> sprites;

};

#endif // SPRITELOADER_H
