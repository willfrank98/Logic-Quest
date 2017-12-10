#include "spriteloader.h"
#include <QDebug>

SpriteLoader::SpriteLoader()
{
    // TODO: Remove these definitions to make more tool-like
    QPixmap *gateSheet = new QPixmap(":/images/sprites/gatesSheet.png");
    QPixmap *blackPipes = new QPixmap(":/images/sprites/pipesBlack.png");
    QPixmap *bluePipes = new QPixmap(":/images/sprites/pipesBlue.png");
    QPixmap *redPipes = new QPixmap(":/images/sprites/pipesRed.png");
    QPixmap *otherGates = new QPixmap(":/images/sprites/otherGates.png");

    // Misc.
    sprites.insert("empty", QPixmap(":/images/sprites/transparent.png"));
    sprites.insert("gatespot", otherGates->copy(64, 128, 64, 64));

    // Start/end gates
    sprites.insert("s0", otherGates->copy(0, 64, 64, 64));
    sprites.insert("s1", otherGates->copy(0, 0, 64, 64));
    sprites.insert("e0", otherGates->copy(64, 64, 64, 64));
    sprites.insert("e1", otherGates->copy(64, 0, 64, 64));
    sprites.insert("ee", otherGates->copy(0, 128, 64, 64));

    // Logic gates
    sprites.insert("andgate", gateSheet->copy(0, 0, 64, 64));
    sprites.insert("orgate", gateSheet->copy(0, 64, 64, 64));
    sprites.insert("nandgate", gateSheet->copy(64, 0, 64, 64));
    sprites.insert("norgate", gateSheet->copy(0, 128, 64, 64));
    sprites.insert("notgate", gateSheet->copy(64, 128, 64, 64));
    sprites.insert("xorgate", gateSheet->copy(64, 64, 64, 64));

    // Black pipes
    sprites.insert("wnpipe", blackPipes->copy(64, 64, 64, 64));
    sprites.insert("enpipe", blackPipes->copy(0, 64, 64, 64));
    sprites.insert("wspipe", blackPipes->copy(64, 0, 64, 64));
    sprites.insert("espipe", blackPipes->copy(0, 0, 64, 64));
    sprites.insert("wepipe", blackPipes->copy(0, 128, 64, 64));
    sprites.insert("nspipe", blackPipes->copy(64, 128, 64, 64));

    // Blue pipes
    sprites.insert("b_wnpipe", bluePipes->copy(64, 64, 64, 64));
    sprites.insert("b_enpipe", bluePipes->copy(0, 64, 64, 64));
    sprites.insert("b_wspipe", bluePipes->copy(64, 0, 64, 64));
    sprites.insert("b_espipe", bluePipes->copy(0, 0, 64, 64));
    sprites.insert("b_wepipe", bluePipes->copy(0, 128, 64, 64));
    sprites.insert("b_nspipe", bluePipes->copy(64, 128, 64, 64));

    // Red pipes
    sprites.insert("r_wnpipe", redPipes->copy(64, 64, 64, 64));
    sprites.insert("r_enpipe", redPipes->copy(0, 64, 64, 64));
    sprites.insert("r_wspipe", redPipes->copy(64, 0, 64, 64));
    sprites.insert("r_espipe", redPipes->copy(0, 0, 64, 64));
    sprites.insert("r_wepipe", redPipes->copy(0, 128, 64, 64));
    sprites.insert("r_nspipe", redPipes->copy(64, 128, 64, 64));
}

// Returns a pixmap from the passed spritesheet.
QPixmap SpriteLoader::getSprite(QString sheetName, QSize frameSize, int frame)
{
    QPixmap sheet = QPixmap(sheetName);
    QSize sheetDimen = QSize(sheet.width() / frameSize.width(), sheet.height() / frameSize.height());
    QRect frameRect = QRect();
    int currentFrame = 0;
    for (int y = 0; y < sheetDimen.height(); y++)
    {
        for (int x = 0; x < sheetDimen.width(); x++)
        {
            if (currentFrame == frame)
            {
                frameRect = QRect(x * frameSize.width(), y * frameSize.height(), frameSize.width(), frameSize.height());
                return sheet.copy(frameRect);
            }
            currentFrame++;
        }
    }

    // Returns the last frame in the sheet if the desired one was not found.
    return sheet.copy(QRect());
}

//Returns a list of pixmaps that hold the sprites for gates.
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

//Returns a list of the names for each gate.
QList<QString> SpriteLoader::getGateNames()
{
    QList<QString> gateNames;
    for (int i = 0; i < sprites.values().size(); i++)
    {
        if (sprites.keys().at(i).endsWith("gate"))
        {
            QString key = sprites.keys().at(i);
            gateNames.append(key.mid(0, key.size() - 4));
        }
    }
    return gateNames;
}
