/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * basicscene.h
 */

#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "basicscene.h"

class Tutorial : public BasicScene
{
public:
	Tutorial();

private:
//	int currentButton = Qt::NoButton;
//	QGraphicsItem *clickedItem;

	void onInit();
	void onUpdate(qreal delta);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
};

#endif // TUTORIAL_H
