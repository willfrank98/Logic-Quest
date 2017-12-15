/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * physicsscene.h
 */

#ifndef PHYSICSSCENE_H
#define PHYSICSSCENE_H

#include <Box2D.h>
#include <basicscene.h>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QResizeEvent>

class PhysicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PhysicsScene(QObject *parent = nullptr);
    ~PhysicsScene();

    void createBox(QRectF rect, QColor line = QColor(0, 0, 0), QColor fill = QColor(255, 255, 255),
                   PhysicsBodyType physicsType = Static, bool draggable = false);
    QGraphicsItem* createSprite(QPixmap& pm, QRectF rect, QColor line, QColor fill,
                   PhysicsBodyType physicsType = Static, bool draggable = false);

private:
    QTimer timer;
    QElapsedTimer deltaKeeper;

    b2Vec2 gravity;
    b2World *world;

    virtual void updateBodies();
    virtual void onInit();
    virtual void onUpdate(qreal delta);
    void attachBody(QGraphicsItem *item, PhysicsBodyType bodyType);

    virtual bool eventFilter(QObject *watched, QEvent *event);

signals:
    void changeScene(QString);
    void endProgram();

public slots:
};

#endif // PHYSICSSCENE_H
