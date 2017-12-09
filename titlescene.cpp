/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * titlescene.cpp
 */

#include "titlescene.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QPainter>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QMediaPlayer>


// Simple example of a title scene
TitleScene::TitleScene()
{

}

// This gets run when the scene is first shown
void TitleScene::onInit()
{
    // Create a static box representing the ground
    // Just gonna leave this enabled until the sprite loading is working
    createBox(QRectF(0.0, sceneRect().height() - 16.0, sceneRect().width(), 16.0),
              QColor(0, 0, 0), QColor(100, 120, 255));

    // Define a font
    QFont font = QFont("Helvetica");

    // Add some text, ignores physics
    // Perhaps move this to a 'createText' method or something
    font.setPointSize(28);

    //Logo
    QPixmap *logoPix = new QPixmap(":/images/logos/mainLogo.png");
    QGraphicsPixmapItem *pixItem = addPixmap(*logoPix);

    //Commented out for now
//    QMediaPlayer *musicPlayer = new QMediaPlayer;
//    musicPlayer->setMedia(QUrl(":/sounds/Visager_-_02_-_Royal_Entrance.mp3"));
//    musicPlayer->setVolume(50);
//    musicPlayer->play();

    // Creates a vector that contains a pixmap of each logic gate.
    QPixmap gatesPM(":images/sprites/gatesSheet.png");
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 2; col++){
            QRect rec(col*64, row*64, 64, 64);
            QPixmap pmc = gatesPM.copy(rec);
            logicGatesPM.append(pmc);
        }
    }


// Adds more text
//    font.setPointSize(14);
//    QGraphicsTextItem *prompt = addText("Press SPACE to play!", font);
//    prompt->setPos(sceneRect().width() / 2.0 - prompt->boundingRect().width() / 2.0, sceneRect().height() / 2.0);
//    prompt->setZValue(1.0);
//    prompt->setData(Name, "prompt");
//    prompt->setData(Direction, 1.0);

    //Sets up menu buttons
    QPushButton *startButton = new QPushButton();
    startButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .45, sceneRect().width() * .30, sceneRect().height() * .10));
    startButton->setText("Start Game");
    startButton->setAttribute(Qt::WA_TranslucentBackground);
    startButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    startButtonProxy = addWidget(startButton);
    startButtonProxy->setZValue(10.0);  // Makes the buttons appear in front of other things

    QPushButton *levelSelectButton = new QPushButton();
    levelSelectButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .57, sceneRect().width() * .30, sceneRect().height() * .10));
    levelSelectButton->setText("Level Select");
    levelSelectButton->setAttribute(Qt::WA_TranslucentBackground);
    levelSelectButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    levelSelectButtonProxy = addWidget(levelSelectButton);
    levelSelectButtonProxy->setZValue(10.0);

    QPushButton *optionsButton = new QPushButton();
    optionsButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .69, sceneRect().width() * .30, sceneRect().height() * .10));
    optionsButton->setText("Options");
    optionsButton->setAttribute(Qt::WA_TranslucentBackground);
    optionsButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    optionsButtonProxy = addWidget(optionsButton);
    optionsButtonProxy->setZValue(10.0);

    QPushButton *exitButton = new QPushButton();
    exitButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .81, sceneRect().width() * .30, sceneRect().height() * .10));
    exitButton->setText("Exit");
    exitButton->setAttribute(Qt::WA_TranslucentBackground);
    exitButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    exitButtonProxy = addWidget(exitButton);
    exitButtonProxy->setZValue(10.0);

    //Connects menu buttons
    connect(startButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelSelectButton, &QPushButton::clicked, this, [=](){emit(changeScene("levelmenu"));}, Qt::QueuedConnection);
    connect(optionsButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(exitButton, &QPushButton::clicked, this, [=](){emit(endProgram());}, Qt::QueuedConnection);




}

// This gets run every 'tick'
void TitleScene::onUpdate(qreal delta)
{
    // Drops a gate every 50 ticks
    // A tick is the length of the 'timer' interval in the BasicScene/PhysicsScene
    if (tickCounter > 50)
    {
        // generates a random index used to grab a pixmap.
        createGate(logicGatesPM[lgIndex] , QRectF(10.0, 8.0, 64.0, 64.0),
                  QColor(0, 0, 0, 0), QColor(0, 0, 0, 0), Dynamic);
        tickCounter = 0;
        lgIndex++;
        if(lgIndex > 5) {
            lgIndex = 0;
        }
    }

//    for (QGraphicsItem *item : items())
//    {
//        if (item->isWidget())
//        {
//            QGraphicsProxyWidget *proxyItem = (QGraphicsProxyWidget*)item;
//            if (proxyItem->scale() > 1.25)
//            {
//                proxyItem->setData(Direction, -1.0);
//            }
//            else if (proxyItem->scale() <= 1.0)
//            {
//                proxyItem->setData(Direction, 1.0);
//            }
//            proxyItem->moveBy(-0.25 * proxyItem->data(Direction).toFloat(), 0.0);
//            proxyItem->setScale(proxyItem->scale() + proxyItem->data(Direction).toFloat() * 0.0025);
//        }
//    }

    tickCounter++;
}
/*
void TitleScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    currentButton = event->button();
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
    if (item != nullptr) clickedItem = item;
}

void TitleScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    currentButton = Qt::NoButton;
    clickedItem = nullptr;
}


void TitleScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (currentButton == Qt::LeftButton && clickedItem != nullptr)
    {
        QPointF newPos = event->scenePos() -
                QPointF(clickedItem->boundingRect().size().width(), clickedItem->boundingRect().size().height()) / 2.0;

        // Perhaps pass a bool that awakens the moved physics body upon mouse release?
        setItemPos(clickedItem, newPos);
    }
}
*/
void TitleScene::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Space)
    {
        // Switch to the tutorial
        emit changeScene("tutorial");
    }

    if (event->key() == Qt::Key_Return)
    {
        emit changeScene("levelmenu");
    }
}
