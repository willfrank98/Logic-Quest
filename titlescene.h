/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * titlescene.h
 */

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include <physicsscene.h>
#include <QVector>
#include <QMediaPlayer>


class TitleScene : public PhysicsScene
{
public:
    TitleScene();

signals:
    void musicSelected(int);
    //void endProgram();

private slots:
    //void tutorial();

private:
    int currentButton = Qt::NoButton;
    int tickCounter = 0;
    int lgIndex = 0;    //used for alternating which logic block is dropped
    QIcon *soundItem;
    QPushButton *soundButton;
    QMediaPlayer* musicPlayer;
    QGraphicsItem *clickedItem;
    QGraphicsProxyWidget *startButtonProxy;
    QGraphicsProxyWidget *levelSelectButtonProxy;
    QGraphicsProxyWidget *optionsButtonProxy;
    QGraphicsProxyWidget *exitButtonProxy;
    QGraphicsProxyWidget *soundButtonProxy;
    QVector<QPixmap> logicGatesPM;

    void onInit();
    void onUpdate(qreal delta);

    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void enableDisableSound();
    void endMusic();
};

#endif // TITLESCENE_H
