/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * basicscene.cpp
 */

#include "basicscene.h"
#include <QDrag>
#include <QMimeData>
#include <iostream>
#include <QButtonGroup>

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
//    qDebug() << "Override the onInit method, dummy!";
}

// This gets called every 'tick'
void BasicScene::onUpdate(qreal delta)
{
//    qDebug() << "Override the onUpdate method, dummy!";
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

void BasicScene::mousePressEvent(QMouseEvent *event)
{

}

void BasicScene::mouseReleaseEvent(QMouseEvent *event)
{

}

void BasicScene::mouseMoveEvent(QMouseEvent *event)
{

}

void BasicScene::keyPressEvent(QKeyEvent *event)
{

}

void BasicScene::keyReleaseEvent(QKeyEvent *event)
{

}

void BasicScene::createBasicUI(int inputs, int outputs, int gridX, int gridY)
{
	qreal width = sceneRect().width();
	qreal height = sceneRect().height();

	int trayWidth = width/12;
	int trayHeight = 100;
	createBox(QRectF(0, 0, trayWidth, height-trayWidth));	//draws input tray
	createBox(QRectF(width-trayWidth, 0, trayWidth, height-trayWidth)); //draws output tray
	createBox(QRectF(0, height-trayHeight, width, trayHeight)); //draws draggables tray

	int gridWidth = (width - (2 * trayWidth)) / gridX;
	int gridHeight = (height - trayHeight) / gridY;

	//TODO: make grid fill available space better
	for (int x = trayWidth; x < width - trayWidth - 5; x += gridWidth)
	{
		for (int y = 0; y < height - trayHeight - 5; y += gridHeight)
		{
			createBox(QRectF(x, y, gridWidth, gridHeight));
		}
	}

	int inBuf = ((gridY - inputs) / 2) * gridHeight + (gridHeight / 2) - 5; //calculates the space between the top of the window and the first input indicator

	for (int i = 0; i < inputs; i++)
	{
		createBox(QRectF(trayWidth - 10, inBuf, 10, 10), QColor(0, 0, 0), QColor(0, 0, 0));
		inBuf += gridHeight;
	}

	int outBuf = ((gridY - outputs) / 2) * gridHeight + (gridHeight / 2) - 5;

	for (int i = 0; i < outputs; i++)
	{
		createBox(QRectF(width - trayWidth, outBuf, 10, 10), QColor(0, 0, 0), QColor(0, 0, 0));
		outBuf += gridHeight;
	}
}

// drag and drop for logic gate buttons
//void BasicScene::gateClicked(int row, int col)
//{
//    QDrag *drag = new QDrag(this);
//    QMimeData *mimeData = new QMimeData;
//    QPixmap pmc = getGatePixmap(row, col);
//    drag->setMimeData(mimeData);
//    drag->setPixmap(pmc);
//    // im thinking about useing this to get loc on screen, when droped
//    Qt::DropAction da = drag->exec();
//}

//  create push button for each logic gate and place in tool bar
void BasicScene::addGatesOnToolbar()
{
    qreal width = sceneRect().width();
    qreal height = sceneRect().height();
    int gateLocation = width/10;
    int space = gateLocation;
    int index = 0;
    QPushButton *logicGates[6];
    QButtonGroup *btnGroup = new QButtonGroup();
    for (QPixmap gate : sl->getGates())
    {
        logicGates[index] = new QPushButton();
        logicGates[index]->setIcon(QIcon(gate));
        logicGates[index]->setIconSize(gate.size());
        logicGates[index]->setGeometry(gateLocation+=gate.width(), height-68, gate.width() + 2, gate.height() + 2);
        logicGates[index]->setEnabled(true);
        logicGates[index]->setCheckable(true);
        btnGroup->addButton(logicGates[index]);
        addWidget(logicGates[index]);

        // I might be easier to just toggle the active gate to place in a spot
        connect(logicGates[index], &QPushButton::pressed, this, [=](){
            for (QAbstractButton *btn : btnGroup->buttons())
            {
                btn->setEnabled(true);
            }
            logicGates[index]->setEnabled(false);
        });
    }

    // connect each logic gate button to forwarding method
//    connect(logicGates[0], SIGNAL(pressed()), this, SLOT(gate0()));
//    connect(logicGates[1], SIGNAL(pressed()), this, SLOT(gate1()));
//    connect(logicGates[2], SIGNAL(pressed()), this, SLOT(gate2()));
//    connect(logicGates[3], SIGNAL(pressed()), this, SLOT(gate3()));
//    connect(logicGates[4], SIGNAL(pressed()), this, SLOT(gate4()));
//    connect(logicGates[5], SIGNAL(pressed()), this, SLOT(gate5()));
}

//// sets the location in the toolbar for the given logic gate
//QPushButton *BasicScene::setGateInToolbar(QPushButton *pb, QPixmap *pm, int xLoc, int yLoc)
//{
//    QIcon buttonIcon(*pm);
//    pb->setIcon(buttonIcon);
//    pb->setIconSize(pm->rect().size());
//    pb->setGeometry(QRect(QPoint(xLoc, yLoc), QSize(64, 64)));
//    pb->setEnabled(true);
//    return pb;
//}

//// returns desired log gate pixmap from sheet
//QPixmap BasicScene::getGatePixmap(int row, int col)
//{
//    QPixmap pm(":/images/sprites/gatesSheet.png");
//    QRect rec(64*col, 64*row, 64, 64);
//    return pm.copy(rec);
//}

//// forwarding methods for dragging gates
//void BasicScene::gate0(){gateClicked(0, 0);}
//void BasicScene::gate1(){gateClicked(0, 1);}
//void BasicScene::gate2(){gateClicked(1, 0);}
//void BasicScene::gate3(){gateClicked(1, 1);}
//void BasicScene::gate4(){gateClicked(2, 0);}
//void BasicScene::gate5(){gateClicked(2, 1);}
