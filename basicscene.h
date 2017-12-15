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
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDrag>
#include <QMimeData>
#include <iostream>
#include <QButtonGroup>
#include <string>
#include <QString>
#include <QMessageBox>

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
    QGraphicsPixmapItem* createSprite(QPointF pos, QSize scale, QString sheet, QSize frameSize, int frame);
    QGraphicsPixmapItem* createGate(QPointF pos, QSize scale, QString gate);
    void setItemPos(QGraphicsItem *item, QPointF pos);
    void createUI();
    void addGatesOnToolbar();
    int getScore();
    void setScore(int points);
    QVector<QPushButton*> gateButtons;

private:
    QTimer timer;
    QElapsedTimer deltaKeeper;
    QMediaPlaylist *playlist;
    QMediaPlayer *soundEffect, *musicPlayer;
    SpriteLoader *sl = new SpriteLoader();
    QPushButton* enableMusicButton;
    QGraphicsProxyWidget* backToHomeProxy;
    QGraphicsProxyWidget* selectMenuProxy;
    QGraphicsProxyWidget* enableMusicButtonProxy;

    virtual void onInit();
    virtual void onUpdate(qreal delta);

    virtual bool eventFilter(QObject *watched, QEvent *event);

    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);

    void enableDisableSound();
    void SoundEffectSelect(int);
    void endMusic();

    int score;
    int numCols;
    int numRows;
    int *inputs;
    int tickTracker = 0;
    int mascotFrame = 0;
    int dialogFrame = 0;
    QGraphicsItem* mascot;
    QGraphicsItem* mascotDialog;
    QList<QPixmap> mascotTalkFrames;
    QList<QPixmap> mascotMoveFrames;
    Level currentLevel;
    QVector<int> goals;
    QVector<GatePipeTags> grid;
    QPushButton *currentSelectedGate;
    QPixmap getGatePixmap(QString string);
    QString gateNames[6] = {"andgate", "nandgate", "norgate", "notgate", "orgate", "xorgate"};
    GateNodeType gateDes[6] = {AND, NAND, NOR, NOT, OR, XOR};
    GateNodeType getGateNodeType(QString name);
    void updateEndGateSprite(int location, int value, int gridWidth, int gridHeight);

signals:
    void changeScene(QString);
    void changeResolution(QString);
public slots:
};

#endif // BASICSCENE_H
