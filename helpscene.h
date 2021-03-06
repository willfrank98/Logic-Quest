/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * helpscene.h
 */

#ifndef HELPSCENE_H
#define HELPSCENE_H
#include "basicscene.h"
#include "spriteloader.h"
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class HelpScene : public BasicScene
{
public:
    HelpScene();
    void onInit();

private: 
    QMediaPlaylist* playlist;
    QMediaPlayer* musicPlayer;
    QMediaPlayer* soundEffect;

    QGraphicsProxyWidget* backToHomeProxy;
    QGraphicsProxyWidget* andGateProxy;
    QGraphicsProxyWidget* nandGateProxy;
    QGraphicsProxyWidget* orGateProxy;
    QGraphicsProxyWidget* norGateProxy;
    QGraphicsProxyWidget* xorGateProxy;
    QGraphicsProxyWidget* notGateProxy;
    QGraphicsProxyWidget* truthTableProxy;

    void updateTruthTable(QString name);
    QPixmap* truthTable;
    QGraphicsPixmapItem *truthTableItem;
    QPixmap* speechBubble;
    QGraphicsPixmapItem *speechBubbleItem;

    SpriteLoader* sl = new SpriteLoader();
    QGraphicsItem* mascot;
    QList<QPixmap> mascotFrames;
    int mascotFrame = 0;
    int tickTracker = 0;

    void onUpdate(qreal delta);

};

#endif // HELPSCENE_H
