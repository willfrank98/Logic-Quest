#include "tutorial.h"
//#include <QDebug>
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
}

void Tutorial::onUpdate(qreal delta)
{

}

void Tutorial::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Tutorial::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

}

void Tutorial::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void Tutorial::keyPressEvent(QKeyEvent *event)
{

}
