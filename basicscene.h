/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * basicscene.h
 */

#ifndef BASICSCENE_H
#define BASICSCENE_H

#include <itemdata.h>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTimer>
#include <QElapsedTimer>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QResizeEvent>
#include <QGraphicsRectItem>
#include <QPushButton>

class BasicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BasicScene(QObject *parent = nullptr);
    ~BasicScene();

    void createBox(QRectF rect, QColor line = QColor(0, 0, 0), QColor fill = QColor(255, 255, 255),
                   bool draggable = false);
    void setItemPos(QGraphicsItem *item, QPointF pos);

	void createBasicUI(int inputs, int outputs, int gridX, int gridY);
    void addGatesOnToolbar();

private:
    QTimer timer;
    QElapsedTimer deltaKeeper;

    virtual void onInit();
    virtual void onUpdate(qreal delta);

    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

signals:
    void changeScene(QString);
public slots:
    void gateClicked();
};

#endif // BASICSCENE_H
