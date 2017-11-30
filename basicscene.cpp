#include "basicscene.h"

// Initializes the world and such
BasicScene::BasicScene(QObject *parent) : QGraphicsScene(parent)
{
    timer.setInterval(8);
    connect(&timer, &QTimer::timeout, this, [=](){
        onUpdate(deltaKeeper.elapsed() / 1000.0);
        deltaKeeper.restart();
    });
}

BasicScene::~BasicScene()
{

}

// Runs this function when the scene is first shown
void BasicScene::onInit()
{
    qDebug() << "Override the onInit method, dummy!";
}

// This gets called every 'tick'
void BasicScene::onUpdate(qreal delta)
{
    qDebug() << "Override the onUpdate method, dummy!";
}

// Creates a box
void BasicScene::createBox(QRectF rect, QColor line, QColor fill, bool draggable)
{
    // Create the GraphicsItem
    QGraphicsRectItem *item = addRect(QRectF(0.0, 0.0, rect.width(), rect.height()), QPen(line), QBrush(fill));
    item->setTransformOriginPoint(rect.width() / 2.0, rect.height() / 2.0);
    item->setPos(rect.x(), rect.y());

    // TODO: Make sure setting all of these is still necessary
    item->setData(Bounds, rect);
    item->setData(Draggable, draggable);
}

// Sets the position of a body (and by extension, an item)
void BasicScene::setItemPos(QGraphicsItem *item, QPointF pos)
{
    if (item->data(Draggable).toBool())
    {
        item->setPos(pos);
    }
}

// Intercept events from the GraphicsView and do things with them.
bool BasicScene::eventFilter(QObject *watched, QEvent *event)
{
    // Call onInit() and start the timer when first shown.
    if (event->type() == QEvent::Show)
    {
        onInit();
        timer.start();
        deltaKeeper.start();
    }

    // Center things upon window resize
    else if (event->type() == QEvent::Resize)
    {
        timer.stop();
        QGraphicsView *gView = static_cast<QGraphicsView*>(watched);
        QSizeF oldSize = sceneRect().size();
        setSceneRect(gView->rect());
        QSizeF offset = (sceneRect().size() - oldSize) / 2.0;
        for (QGraphicsItem *item : items())
        {
            item->setPos(item->pos().x() + offset.width(),
                         item->pos().y() + offset.height());
        }
        timer.start();
    }

    // Passes the event to be handled in the default manner
    return QGraphicsScene::eventFilter(watched, event);
}

void BasicScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void BasicScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void BasicScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void BasicScene::keyPressEvent(QKeyEvent *event)
{

}

void BasicScene::keyReleaseEvent(QKeyEvent *event)
{

}

void BasicScene::createUI()
{
	qreal width = sceneRect().width();
	qreal height = sceneRect().height();

	createBox(QRectF(0, 0, 100, height-100));
	createBox(QRectF(width-100, 0, 100, height-100));
	createBox(QRectF(0, height-100, width, 100));

}
