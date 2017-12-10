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
#include <string>
#include <QString>
#include <QGraphicsItem>

bool enableMusic = true;

// Initializes the world and such
BasicScene::BasicScene(QObject *parent, int cols, int rows, int *inputs, QVector<int> goals, QVector<GatePipeTags> grid) : QGraphicsScene(parent)
{
    timer.setInterval(8);
    connect(&timer, &QTimer::timeout, this, [=](){
        onUpdate(deltaKeeper.elapsed() / 1000.0);
        deltaKeeper.restart();
    });

    this->numCols = cols;
    this->numRows = rows;
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

    currentLevel = level;
    this->numCols = level.getNumColumns();
    this->numRows = level.getNumRows();
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

QGraphicsPixmapItem* BasicScene::createSprite(QPointF pos, QSize scale, QString sheet, QSize frameSize, int frame)
{
    QPixmap sprite = sl->getSprite(sheet, frameSize, frame).scaled(scale);
    QGraphicsPixmapItem *item = addPixmap(sprite);
    item->setPos(pos);
    item->setData(Sheet, sheet);
    item->setData(FrameSize, frameSize);
    item->setData(Frame, frame);

    return item;
}

QGraphicsPixmapItem* BasicScene::createGate(QPointF pos, QSize scale, QString gate)
{
    int frame = -1;
    if (gate == "andgate") frame = 0;
    else if(gate == "nandgate") frame = 1;
    else if(gate == "orgate") frame = 2;
    else if(gate == "xorgate") frame = 3;
    else if(gate == "norgate") frame = 4;
    else if(gate == "notgate") frame = 5;
    else return new QGraphicsPixmapItem();

    return createSprite(pos, scale, ":/images/sprites/gatesSheet.png", QSize(64, 64), frame);
}

// Sets the position of a body (and by extension, an item)
void BasicScene::setItemPos(QGraphicsItem *item, QPointF pos)
{
    if (item->data(Draggable).toBool())
    {
        item->setPos(pos);
    }
}
// drag for palcing buttons
void BasicScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    // maybe highlight something or set somehting active if over certain space, etc
    QGraphicsSceneDragDropEvent *g = (QGraphicsSceneDragDropEvent*)event;
    g->setDropAction(Qt::CopyAction); // not sure about this
    qDebug() << g->scenePos();
}

// drop event for buttons
void BasicScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<< currentLevel.getGoals().size() << ",,:pppp";
    qDebug()<< currentLevel.getEndGates().size() <<"<gg";
    currentSelectedGate->setEnabled(true);
    QGraphicsSceneDragDropEvent *g = (QGraphicsSceneDragDropEvent*)event;
    qreal width = sceneRect().width();
    qreal height = sceneRect().height();
    int trayHeight = 100;
    if (g->scenePos().y() > height - trayHeight) return;
	int gridWidth = width / numCols;
    int gridHeight = (height - trayHeight) / numRows;

	int xOff = ((int)(g->scenePos().x())) % gridWidth;
    int yOff = ((int)(g->scenePos().y())) % gridHeight;
    int xL = g->scenePos().x() - xOff;
    int yL = g->scenePos().y() - yOff;

    if (currentLevel.getLayout()[xL/gridWidth + yL/gridHeight*numCols] == UG) {

        createGate(QPointF(xL, yL), QSize(gridWidth, gridHeight),  currentSelectedGate->accessibleName());
        qDebug() << gateDes[currentSelectedGate->accessibleDescription().toInt()];
        qDebug() <<  yL/gridHeight << xL/gridWidth;
        qDebug() << yL/gridHeight*numCols+ xL/gridWidth;
        qDebug() << numCols;
     //  this
        int gateNodeLocation = currentLevel.getGateNodeIndex(yL/gridHeight*numCols + xL/gridWidth);
        QVector<int> endGateUpdate;
        endGateUpdate = currentLevel.setGateType(gateNodeLocation,
                                                 gateDes[currentSelectedGate->accessibleDescription().toInt()]);

        //If the endGate is updated and returns a vector of the location and new value
        //Update the endGate Sprite
        if(endGateUpdate.size() > 0)
        {
            updateEndGateSprite(endGateUpdate[0], endGateUpdate[1], gridWidth, gridHeight);
        }
    }
    //TODO update back end..add gate to vecctor of in use gates?
}

//GateNodeType getGateNodeType(QString name) {
//	return nullptr;
//}


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
            qreal width = sceneRect().width();
            qreal height = sceneRect().height();

            int trayWidth = width/12;
            int trayHeight = 100;

            int gridWidth = (width - (2 * trayWidth)) / numCols;
            int gridHeight = (height - trayHeight) / numRows;

            int x = (mev->x() - trayWidth)/gridWidth;
            int y = mev->y()/gridHeight;

            qDebug() << "x, y :" << x << y;
            qDebug() << itemAt(mev->localPos(), QTransform())->data(Name);
        }
    }

    // Passes the event to be handled in the default manner
    return QGraphicsScene::eventFilter(watched, event);
}

void BasicScene::createUI()
{
	qreal width = sceneRect().width();
	qreal height = sceneRect().height();

	//int trayWidth = width/12;
	int trayHeight = 100;
//    createBox(QRectF(0, height-trayHeight, width, trayHeight)); //draws draggables tray
    createBox(QRectF(0, height-trayHeight, width, trayHeight), QColor(166, 170, 178), QColor(166, 170, 178), false);

    QPixmap *backPix = new QPixmap(":/images/icons/BackArrow.png");
    QIcon *backIcon = new QIcon(*backPix);
    QPushButton* backButton = new QPushButton();
    backButton->setGeometry(QRect(10, sceneRect().height()*0.87, 60, 40));
    backButton->setIcon(*backIcon);
    backButton->setAttribute(Qt::WA_TranslucentBackground);
    backButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}"
                              );
    backToHomeProxy = addWidget(backButton);
    backToHomeProxy->setZValue(10.0);

    QPushButton* selectMenuButton = new QPushButton();
    selectMenuButton->setGeometry(QRect(10, sceneRect().height()*0.93, 60, 40));
    selectMenuButton->setAttribute(Qt::WA_TranslucentBackground);
    selectMenuButton->setText("Level Menu");
    selectMenuButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 10px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}"
                              );
    selectMenuProxy = addWidget(selectMenuButton);
    selectMenuProxy->setZValue(10.0);

    /* Add Connection to get Back to home screen */
    connect(backButton, &QPushButton::clicked, this, [=](){emit(changeScene("title"));}, Qt::QueuedConnection);
    connect(selectMenuButton, &QPushButton::clicked, this, [=](){emit(changeScene("levelmenu"));}, Qt::QueuedConnection);

	int gridWidth = width / numCols;
    int gridHeight = (height - trayHeight) / numRows;

    //TODO: make grid fill available space better
    int itemNum = 0;
    for (int y = 0; y < height - trayHeight - numRows; y += gridHeight)
    {
		for (int x = 0; x < width - numCols; x += gridWidth)
        {
            // Switch case matching the desired data to pass to our SpriteLoader tool.
            QString sheet;
            int frame;
            switch(grid[itemNum])
            {
            case WN:
                sheet = ":/images/sprites/pipesBlack.png";
                frame = 3;
                break;
            case EN:
                sheet = ":/images/sprites/pipesBlack.png";
                frame = 2;
                break;
            case WS:
                sheet = ":/images/sprites/pipesBlack.png";
                frame = 1;
                break;
            case ES:
                sheet = ":/images/sprites/pipesBlack.png";
                frame = 0;
                break;
            case WE:
                sheet = ":/images/sprites/pipesBlack.png";
                frame = 4;
                break;
            case NS:
                sheet = ":/images/sprites/pipesBlack.png";
                frame = 5;
                break;
            case S0:
                sheet = ":/images/sprites/otherGates.png";
                frame = 2;
                break;
            case S1:
                sheet = ":/images/sprites/otherGates.png";
                frame = 0;
                break;
            case EG:
                sheet = ":/images/sprites/otherGates.png";
                frame = 4;
                break;
            case UG:
                sheet = ":/images/sprites/otherGates.png";
                frame = 5;
                break;
            default:
                break;
            }

            createSprite(QPointF(x, y), QSize(gridWidth, gridHeight), sheet, QSize(64, 64), frame);
            if (sheet != "")
            {
                createSprite(QPointF(x, y), QSize(gridWidth, gridHeight), sheet, QSize(64, 64), frame);
            }
            itemNum++;
		}
	}
}

//  create push button for each logic gate and place in tool bar
void BasicScene::addGatesOnToolbar()
{
    qreal width = sceneRect().width();
    qreal height = sceneRect().height();
    int gateLocation = width/10;
	//int space = gateLocation;
    int index = 0;
    QPushButton *logicGates[6];
    QButtonGroup *btnGroup = new QButtonGroup();

    for (QPixmap gate : sl->getGates())
    {
        logicGates[index] = new QPushButton();
        logicGates[index]->setAttribute(Qt::WA_TranslucentBackground);
        logicGates[index]->setIcon(QIcon(gate));
        logicGates[index]->setIconSize(gate.size());
		logicGates[index]->setGeometry(gateLocation+=gate.width(), height-68, gate.width() + 2, gate.height() + 2);
        logicGates[index]->setEnabled(true);
        logicGates[index]->setCheckable(true);
        logicGates[index]->setAccessibleName(gateNames[index]);
        logicGates[index]->setAccessibleDescription(QString::number(index));
        qDebug() << logicGates[index]->accessibleName();
        btnGroup->addButton(logicGates[index]);
        addWidget(logicGates[index]);

        // It might be easier to just toggle the active gate to place in a spot
        // Would just have to store the currently selected gate and check against it
        QPushButton* currentButton = logicGates[index];
        connect(currentButton, &QPushButton::pressed, this, [=](){
            currentButton->setChecked(true);
            // need to set name property of QPush button logic gates
            //currentButton->setAccessibleName("nandgate");    // TODO needs to be done correcctly..at time of setting buttons on bottom of sreen
            currentSelectedGate = currentButton;
            currentSelectedGate->setChecked(true);
            currentSelectedGate->setEnabled(false);
            qDebug()<< "currentButton->accessibleName() = "+ currentButton->accessibleName();
            currentSelectedGate->setAccessibleName(currentButton->accessibleName());
            currentSelectedGate->setAccessibleDescription(currentButton->accessibleDescription());
            // drag for log gate onto game space
            QDrag *drag = new QDrag(this);
            QMimeData *mimeData = new QMimeData;
            QPixmap pmc = getGatePixmap(currentButton->accessibleName()); //change row and col THIS IS WHERE DRAG GATE is made
            drag->setMimeData(mimeData);
            drag->setPixmap(pmc);
            QApplication::setOverrideCursor(Qt::ClosedHandCursor);
			/*Qt::DropAction da = */drag->exec(Qt::MoveAction);//???
            QApplication::restoreOverrideCursor();
        });
        index++;
    }

    QString goalSequence = "Goal: ";
    int size = currentLevel.getGoals().size();
    qDebug()<< size;
    QVector<int> allGoals = currentLevel.getGoals();

    for (int i = 0; i < size; i ++) {

        goalSequence.append(QString::number(allGoals[i]));
    }

    QFont font = QFont("Helvetica");
    font.setPointSize(24);
    QGraphicsTextItem *easy = addText(goalSequence, font);
    easy->setPos(sceneRect().width()*0.8, sceneRect().height()*0.88);
}

void BasicScene::updateEndGateSprite(int location, int value, int gridWidth, int gridHeight)
{
    int y = (location/numCols)*gridHeight;
    int x = (location + 1 - ((y/gridHeight)*numCols))*gridHeight;
    qDebug() << y << x;
    QString tag;
    if(value == 0)
    {
        tag = "e0";
    }
    else
    {
        tag = "e1";
    }

    createSprite(QPointF(x, y), QSize(gridWidth, gridHeight),  tag);
}

// returns desired log gate pixmap from sheet
QPixmap BasicScene::getGatePixmap(QString string)
{
    int frame = -1;
    if (string == "andgate") frame = 0;
    else if(string == "nandgate") frame = 1;
    else if(string == "orgate") frame = 2;
    else if(string == "xorgate") frame = 3;
    else if(string == "norgate") frame = 4;
    else if(string == "notgate") frame = 5;
    else qDebug() << "error in gate selection for dragMISTAKE!!!!!!";

    return sl->getSprite(":/images/sprites/gatesSheet.png", QSize(64, 64), frame);
}
