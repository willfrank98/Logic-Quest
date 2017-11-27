#ifndef PHYSICSSCENE_H
#define PHYSICSSCENE_H

#include <Box2D.h>
#include <itemdata.h>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QElapsedTimer>

class PhysicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PhysicsScene(QObject *parent = nullptr);
    ~PhysicsScene();

    void createBox(QRectF rect, QColor line = QColor(0, 0, 0), QColor fill = QColor(255, 255, 255),
                   ItemVal physicsType = Static, bool draggable = false);
    void setItemPos(QGraphicsItem *item, QPointF pos);

private:
    QTimer timer;
    QElapsedTimer deltaKeeper;

    b2Vec2 gravity;
    b2World *world;

    virtual void updateBodies();
    virtual void onInit();
    virtual void onUpdate(qreal delta);

    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

signals:
    void changeScene(QString);

public slots:
};

#endif // PHYSICSSCENE_H
