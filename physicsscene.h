#ifndef PHYSICSSCENE_H
#define PHYSICSSCENE_H

#include <Box2D.h>
#include <basicscene.h>

class PhysicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PhysicsScene(QObject *parent = nullptr);
    ~PhysicsScene();

    void createBox(QRectF rect, QColor line = QColor(0, 0, 0), QColor fill = QColor(255, 255, 255),
                   ItemVal physicsType = Static, bool draggable = false);
    void createGate(const QString& resourceName, QRectF rect, QColor line, QColor fill,
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

signals:
    void changeScene(QString);

public slots:
};

#endif // PHYSICSSCENE_H
