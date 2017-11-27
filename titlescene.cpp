#include "titlescene.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsView>


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
    prompt->setData(ScaleDir, 1.0);
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
                item->setData(ScaleDir, -item->data(ScaleDir).toFloat());
                createBox(QRectF(10.0, -64.0, 64.0, 64.0),
                          QColor(0, 0, 0), QColor(128, 128, 128), Dynamic, true);
            }
            item->moveBy(delta * -item->data(ScaleDir).toFloat() * item->boundingRect().width() / 2.0,
                         delta * item->data(ScaleDir).toFloat());
            item->setScale(item->scale() + delta * item->data(ScaleDir).toFloat());
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
        // Just load the title scene again since we have nothing else yet.
        emit changeScene("Title");
    }
}
