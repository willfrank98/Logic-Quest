#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <QPixmap>
#include <QMap>

class SpriteLoader
{
public:
    SpriteLoader();
    QPixmap getSprite(QString);
    QList<QPixmap> getSprites();

private:
    QMap<QString, QPixmap> sprites;

};

#endif // SPRITELOADER_H
