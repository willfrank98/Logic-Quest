#include "titlescene.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>


// Simple example of a title scene
TitleScene::TitleScene()
{

}

// This gets run when the scene is first shown
void TitleScene::onInit()
{
    // Create a static box representing the ground
    createBox(QRectF(0.0, sceneRect().height() - 16.0, sceneRect().width(), 16.0),
              QColor(0, 0, 0), QColor(128, 128, 128));



    // Create some dynamic boxes
//    createBox(QRectF(sceneRect().width() / 2.0, sceneRect().height() / 2.0, 64.0, 64.0),
//              QColor(0, 0, 0), QColor(128, 128, 128), Dynamic, true);
//    createBox(QRectF(sceneRect().width() / 2.0, sceneRect().height() / 2.0 - 128.0, 64.0, 64.0),
//              QColor(0, 0, 0), QColor(128, 128, 128), Dynamic, true);

    // Define a font
    QFont font = QFont("Helvetica");

    // Add some text, ignores physics
    // Perhaps move this to a 'createText' method or something
    font.setPointSize(28);
    QGraphicsTextItem *title = addText("Logic Gate", font);
    title->setPos(sceneRect().width() / 2.0 - title->boundingRect().width() / 2.0, 20.0);
    title->setZValue(1.0);
    title->setData(Name, "title");

    // Adds more text
    font.setPointSize(14);
    QGraphicsTextItem *prompt = addText("Press SPACE to play!", font);
    prompt->setPos(sceneRect().width() / 2.0 - prompt->boundingRect().width() / 2.0, sceneRect().height() / 2.0);
    prompt->setZValue(1.0);
    prompt->setData(Name, "prompt");
    prompt->setData(Direction, 1.0);

    //Sets up menu buttons
    QPushButton *startButton = new QPushButton();
    startButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .25, sceneRect().width() * .30, sceneRect().height() * .10));
    startButton->setText("Start Game");
    startButtonProxy = addWidget(startButton);

    QPushButton *levelSelectButton = new QPushButton();
    levelSelectButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .40, sceneRect().width() * .30, sceneRect().height() * .10));
    levelSelectButton->setText("Level Select");
    QGraphicsProxyWidget *levelSelectButtonProxy = addWidget(levelSelectButton);

    QPushButton *optionsButton = new QPushButton();
    optionsButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .55, sceneRect().width() * .30, sceneRect().height() * .10));
    optionsButton->setText("Options");
    QGraphicsProxyWidget *optionsButtonProxy = addWidget(optionsButton);

    QPushButton *exitButton = new QPushButton();
    exitButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .70, sceneRect().width() * .30, sceneRect().height() * .10));
    exitButton->setText("Exit");
    QGraphicsProxyWidget *exitButtonProxy = addWidget(exitButton);

    //Connects menu buttons
    connect(startButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));});




}

void TitleScene::tutorial(){
    emit(changeScene("tutorial"));
}

// This gets run every 'tick'
void TitleScene::onUpdate(qreal delta)
{
    for (QGraphicsItem *item : items())
    {
        // Animate the "click to play!" text
        // Perhaps move to some animateItem method that utilizes a timer, or something
        if (item->data(Name) == "prompt")
        {
            if (item->scale() >= 1.5 || item->scale() < 1.0)
            {
                item->setData(Direction, -item->data(Direction).toFloat());
                //createBox(QRectF(10.0, -64.0, 64.0, 64.0),
                  //        QColor(0, 0, 0), QColor(128, 128, 128), Dynamic, true);
                createGate(":/res/sprites/logic_gates_64x64.png", QRectF(10.0, -64.0, 64.0, 64.0),
                          QColor(0, 0, 0), QColor(128, 128, 128), Dynamic, true);
            }
            item->moveBy(delta * -item->data(Direction).toFloat() * item->boundingRect().width() / 2.0,
                         delta * item->data(Direction).toFloat());
            item->setScale(item->scale() + delta * item->data(Direction).toFloat());
        }
    }
}

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

void TitleScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
		// Switch to the tutorial
		emit changeScene("tutorial");
    }
}
