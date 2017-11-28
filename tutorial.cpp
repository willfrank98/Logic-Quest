#include "tutorial.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsView>

Tutorial::Tutorial()
{

}

void Tutorial::onInit()
{
	// Define a font
	QFont font = QFont("Helvetica");

	// Add some text, ignores physics
	font.setPointSize(14);
	QGraphicsTextItem *title = addText("Tutorial", font);
	title->setPos(/*sceneRect().width() / 2.0 - title->boundingRect().width() / 2.0, 20.0*/ 0, 0);
	title->setZValue(1.0);
    title->setData(Name, "title");

    // The click to continue text
    font.setPointSize(14);
    QGraphicsTextItem *cont = addText("Click anywhere to continue ...", font);
    cont->setPos(sceneRect().width() - cont->boundingRect().width(), sceneRect().height() - cont->boundingRect().height());
    cont->setZValue(1.0);
    cont->setData(Name, "cont_prompt");
    cont->setData(StartPosition, cont->pos());  // Start position; this would be a good spot to use an enum
    cont->setData(Direction, 1.0);          // Move direction
}

void Tutorial::onUpdate(qreal delta)
{
    for (QGraphicsItem *item : items())
    {
        // Animate the "click to continue" text
        // Perhaps move to some animateItem method that utilizes a timer, or something
        if (item->data(Name) == "cont_prompt")
        {
            if (item->pos().x() < item->data(StartPosition).toPointF().x() - delta * 1000.0
                    || item->pos().x() > item->data(StartPosition).toPointF().x())
            {
                item->setData(Direction, -item->data(Direction).toFloat());
            }
            item->moveBy(delta * 0.2 * -item->data(Direction).toFloat() * item->boundingRect().width(), 0.0);
        }
    }
}

void Tutorial::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit changeScene("Level1");
}

void Tutorial::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

}

void Tutorial::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void Tutorial::keyPressEvent(QKeyEvent *event)
{

}
