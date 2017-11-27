#ifndef TITLESCENE_H
#define TITLESCENE_H

#include <physicsscene.h>

class TitleScene : public PhysicsScene
{
public:
    TitleScene();

private:
    int currentButton = Qt::NoButton;
    QGraphicsItem *clickedItem;

    void onInit();
    void onUpdate(qreal delta);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // TITLESCENE_H
