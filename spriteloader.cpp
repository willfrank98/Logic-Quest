#include "spriteloader.h"

SpriteLoader::SpriteLoader()
{
    QPixmap *gateSheet = new QPixmap(":/images/sprites/logic_gates_64x64.png");
    QPixmap *blackPipes = new QPixmap(":/images/sprites/pipes_black_64x64.png");
    QPixmap *greenPipes = new QPixmap(":/images/sprites/pipes_green_64x64.png");
    QPixmap *redPipes = new QPixmap(":/images/sprites/pipes_red_64x64.png");

    sprites.insert("andgate", gateSheet->copy(0, 0, 64, 64));
    sprites.insert("orgate", gateSheet->copy(0, 64, 64, 64));
    sprites.insert("nandgate", gateSheet->copy(64, 0, 64, 64));
    sprites.insert("norgate", gateSheet->copy(0, 128, 64, 64));
    sprites.insert("notgate", gateSheet->copy(64, 128, 64, 64));
    sprites.insert("xorgate", gateSheet->copy(64, 64, 64, 64));
}

QPixmap SpriteLoader::getSprite(QString tag)
{
    return sprites.value(tag);
}

QList<QPixmap> SpriteLoader::getSprites()
{
    return sprites.values();
}
