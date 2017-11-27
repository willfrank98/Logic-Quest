#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "physicsscene.h"

class Tutorial : public PhysicsScene
{
public:
	Tutorial();

private:
//	int currentButton = Qt::NoButton;
//	QGraphicsItem *clickedItem;

	void onInit();
	void onUpdate(qreal delta);

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
};

#endif // TUTORIAL_H
