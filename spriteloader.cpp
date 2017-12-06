#include "spriteloader.h"
#include <QDebug>

SpriteLoader::SpriteLoader()
{
    QPixmap *gateSheet = new QPixmap(":/images/sprites/gatesSheet.png");
    QPixmap *blackPipes = new QPixmap(":/images/sprites/pipesBlack.png");
    QPixmap *bluePipes = new QPixmap(":/images/sprites/pipesBlue.png");
    QPixmap *redPipes = new QPixmap(":/images/sprites/pipesRed.png");

    sprites.insert("empty", QPixmap(":/images/sprites/transparent.png"));
    sprites.insert("gatespot", QPixmap(":/images/sprite/gateSpot.png"));

    sprites.insert("andgate", gateSheet->copy(0, 0, 64, 64));
    sprites.insert("orgate", gateSheet->copy(0, 64, 64, 64));
    sprites.insert("nandgate", gateSheet->copy(64, 0, 64, 64));
    sprites.insert("norgate", gateSheet->copy(0, 128, 64, 64));
    sprites.insert("notgate", gateSheet->copy(64, 128, 64, 64));
    sprites.insert("xorgate", gateSheet->copy(64, 64, 64, 64));
}

QPixmap SpriteLoader::getSprite(QString tag)
{
    return sprites.value(tag.toLower());
}

QList<QPixmap> SpriteLoader::getGates()
{
    QList<QPixmap> gates;
    for (int i = 0; i < sprites.values().size(); i++)
    {
        if (sprites.keys().at(i).endsWith("gate"))
        {
            gates.append(sprites.values().at(i));
        }
    }
    return gates;
}
