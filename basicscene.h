/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * basicscene.h
 */

#ifndef BASICSCENE_H
#define BASICSCENE_H

#include <itemdata.h>
#include <spriteloader.h>
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
#include <QGraphicsProxyWidget>

class BasicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BasicScene(QObject *parent = nullptr, int inputs = 1, int outputs = 1, int x = 5, int y = 5);
    ~BasicScene();

    QGraphicsItem* createBox(QRectF rect, QColor line = QColor(0, 0, 0), QColor fill = QColor(255, 255, 255),
                   bool draggable = false);
    void setItemPos(QGraphicsItem *item, QPointF pos);

    void createBasicUI();
    void addGatesOnToolbar();
//    void gateClicked(int row, int col);
private:
    QTimer timer;
    QElapsedTimer deltaKeeper;
    SpriteLoader *sl = new SpriteLoader();

    virtual void onInit();
    virtual void onUpdate(qreal delta);

    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
	virtual void keyReleaseEvent(QKeyEvent *event);

    int inputs;
    int outputs;
    int x;
    int y;
//    void addGatesOnToolbar();
//    void gateClicked(int row, int col);
//    QPixmap getGatePixmap(int row, int col);
//    QPushButton *setGateInToolbar(QPushButton *pb, QPixmap *pm, int xLoc, int yLoc);

signals:
    void changeScene(QString);
public slots:
//    void gate0();
//    void gate1();
//    void gate2();
//    void gate3();
//    void gate4();
//    void gate5();
};

#endif // BASICSCENE_H
