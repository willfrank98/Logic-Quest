#ifndef TITLESCENE_H
#define TITLESCENE_H

#include <physicsscene.h>


class TitleScene : public PhysicsScene
{
public:
    TitleScene();

signals:
    //void endProgram();

private slots:
    //void tutorial();

private:
    int currentButton = Qt::NoButton;
    QGraphicsItem *clickedItem;
    QGraphicsProxyWidget *startButtonProxy;
    QGraphicsProxyWidget *levelSelectButtonProxy;
    QGraphicsProxyWidget *optionsButtonProxy;
    QGraphicsProxyWidget *exitButtonProxy;

    void onInit();
    void onUpdate(qreal delta);

    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // TITLESCENE_H
