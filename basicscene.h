/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * basicscene.h
 */

#ifndef BASICSCENE_H
#define BASICSCENE_H

#include <spriteloader.h>
#include <level.h>
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
#include <QApplication>
#include <QGraphicsSceneDragDropEvent>
#include <QActionGroup>
#include <QtGlobal>

extern bool enableMusic;

class BasicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BasicScene(QObject *parent = nullptr, int numCols = 0, int numRows = 0, int *inputs = nullptr, QVector<int> goals = QVector<int>(), QVector<GatePipeTags> grid = QVector<GatePipeTags>());
    ~BasicScene();

    BasicScene(Level level);

    QGraphicsItem* createBox(QRectF rect, QColor line = QColor(0, 0, 0), QColor fill = QColor(255, 255, 255),
                   bool draggable = false);
    QGraphicsPixmapItem* createSprite(QPointF pos, QSize size, QString tag);
    void setItemPos(QGraphicsItem *item, QPointF pos);

	void createUI();
    void addGatesOnToolbar();
//    void gateClicked(int row, int col);
private:
    QTimer timer;
    QElapsedTimer deltaKeeper;
    SpriteLoader *sl = new SpriteLoader();

    virtual void onInit();
    virtual void onUpdate(qreal delta);

    virtual bool eventFilter(QObject *watched, QEvent *event);
//    virtual void mousePressEvent(QMouseEvent *event);
//    virtual void mouseReleaseEvent(QMouseEvent *event);
//    virtual void mouseMoveEvent(QMouseEvent *event);
//    virtual void keyPressEvent(QKeyEvent *event);
//	virtual void keyReleaseEvent(QKeyEvent *event);

    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);

    int numCols;
    int numRows;
    int *inputs;
    Level currentLevel;
    QVector<int> goals;
    QVector<GatePipeTags> grid;
    QPushButton *currentSelectedGate;
//    void addGatesOnToolbar();
//    void gateClicked(int row, int col);
    QPixmap getGatePixmap(QString string);
    QString gateNames[6] = {"andgate", "nandgate", "norgate", "notgate", "orgate", "xorgate"};
    GateNodeType gateDes[9] = {START, END, UNSET, AND, OR, NAND, NOR, XOR, NOT};
    GateNodeType getGateNodeType(QString name);
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
