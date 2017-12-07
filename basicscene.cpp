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
BasicScene::BasicScene(QObject *parent, int x, int y, int *inputs, QVector<int> goals, QVector<GatePipeTags> grid) : QGraphicsScene(parent)
{
    timer.setInterval(8);
    connect(&timer, &QTimer::timeout, this, [=](){
        onUpdate(deltaKeeper.elapsed() / 1000.0);
        deltaKeeper.restart();
    });

    this->x = x;
    this->y = y;
    this->inputs = inputs;
    this->goals = goals;
    this->grid = grid;
}

BasicScene::BasicScene(Level level)
{
    timer.setInterval(8);
    connect(&timer, &QTimer::timeout, this, [=](){
        onUpdate(deltaKeeper.elapsed() / 1000.0);
        deltaKeeper.restart();
    });

    this->x = level.getNumColumns();
    this->y = level.getNumRows();
    this->goals = level.getGoals();
    this->grid = level.getLayout();

}

BasicScene::~BasicScene()
{

}

// Runs this function when the scene is first shown
void BasicScene::onInit()
{
	createUI();
    addGatesOnToolbar();

}

// This gets called every 'tick'
void BasicScene::onUpdate(qreal delta)
{
//    qDebug() << "Override the onUpdate method, dummy!";
}

// Creates a box
QGraphicsItem* BasicScene::createBox(QRectF rect, QColor line, QColor fill, bool draggable)
{
    // Create the GraphicsItem
    QGraphicsRectItem *item = addRect(QRectF(0.0, 0.0, rect.width(), rect.height()), QPen(line), QBrush(fill));
    item->setTransformOriginPoint(rect.width() / 2.0, rect.height() / 2.0);
    item->setPos(rect.x(), rect.y());

    // TODO: Make sure setting all of these is still necessary
//    item->setData(Bounds, rect);
//    item->setData(Draggable, draggable);

    return item;
}

QGraphicsPixmapItem* BasicScene::createSprite(QPointF pos, QSize size, QString tag)
{
    QGraphicsPixmapItem *item = addPixmap(sl->getSprite(tag).scaled(size));
    item->setPos(pos);
    item->setData(Name, tag);

    return item;
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

    // Handles clicks on the scene, can't click through ProxyWidgets
    else if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mev = (QMouseEvent*)event;
        if (itemAt(mev->localPos(), QTransform()) != nullptr)
        {
            //qDebug() << "Dimensions of clicked box:" << itemAt(mev->localPos(), QTransform())->boundingRect();
            //qDebug() << "x, y :" << mev->x() << mev->y();
            qreal width = sceneRect().width();
            qreal height = sceneRect().height();

            int trayWidth = width/12;
            int trayHeight = 100;

            int gridWidth = (width - (2 * trayWidth)) / x;
            int gridHeight = (height - trayHeight) / y;

            int x = (mev->x() - trayWidth)/gridWidth;
            int y = mev->y()/gridHeight;

            qDebug() << "x, y :" << x << y;
            qDebug() << itemAt(mev->localPos(), QTransform())->data(Name);
        }
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

void BasicScene::createUI()
{
	qreal width = sceneRect().width();
	qreal height = sceneRect().height();

	int trayWidth = width/12;
	int trayHeight = 100;
	createBox(QRectF(0, 0, trayWidth, height-trayWidth));	//draws input tray
	createBox(QRectF(width-trayWidth, 0, trayWidth, height-trayWidth)); //draws output tray
	createBox(QRectF(0, height-trayHeight, width, trayHeight)); //draws draggables tray

    int gridWidth = (width - (2 * trayWidth)) / x;
    int gridHeight = (height - trayHeight) / y;

    //TODO: make grid fill available space better
    int itemNum = 0;
    for (int y = 0; y < height - trayHeight - 5; y += gridHeight)
    {
        for (int x = trayWidth; x < width - trayWidth - 5; x += gridWidth)
        {
            QString tag;
            switch(grid[itemNum])
            {
            case WN:
                tag = "wnpipe";
                break;
            case EN:
                tag = "enpipe";
                break;
            case WS:
                tag = "wspipe";
                break;
            case ES:
                tag = "espipe";
                break;
            case WE:
                tag = "wepipe";
                break;
            case NS:
                tag = "nspipe";
                break;
            case S0:
                tag = "s0gate";
                break;
            case S1:
                tag = "s1gate";
                break;
            case EG:
                tag = "eegate";
                break;
            case UG:
                tag = "gatespot";
                break;
            default:
                tag = "empty";
                break;
            }

            createSprite(QPointF(x, y), QSize(gridWidth, gridHeight), tag);
            itemNum++;
		}
	}

	for (int i = 0; i < x; i++)
	{
		switch (inputs[i])
		{
		case -1:
			//draw no input
			break;
		case 0:
			//draw 0 input
			break;
		case 1:
			//draw 1 input
			break;
		}
	}

	for (int i = 0; i < y; i++)
	{
        switch (goals[i])
		{
		case -1:
			//draw no output
			break;
		case 0:
			//draw 0 output
			break;
		case 1:
			//draw 1 output
			break;
		}
	}

	for (int i = 0; i < (x * y); i ++)
	{

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

        // It might be easier to just toggle the active gate to place in a spot
        // Would just have to store the currently selected gate and check against it
        QPushButton* currentButton = logicGates[index];
        connect(currentButton, &QPushButton::pressed, this, [=](){
            for (QAbstractButton *btn : btnGroup->buttons())
            {
                btn->setEnabled(true);
            }
            currentButton->setEnabled(false);
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
