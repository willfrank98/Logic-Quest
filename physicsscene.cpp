#include "physicsscene.h"
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QResizeEvent>

// Initializes the world and such
PhysicsScene::PhysicsScene(QObject *parent) : QGraphicsScene(parent)
{
    gravity = b2Vec2(0.0, 9.8);
    world = new b2World(gravity);

    timer.setInterval(17);
    connect(&timer, &QTimer::timeout, this, [=](){
        onUpdate(deltaKeeper.elapsed() / 1000.0);
        updateBodies();
        deltaKeeper.restart();
    });
}

PhysicsScene::~PhysicsScene()
{

}

// Runs this function when the scene is first shown
void PhysicsScene::onInit()
{
    qDebug() << "Override the onInit method, dummy!";
}

// This gets called every 'tick'
void PhysicsScene::onUpdate(qreal delta)
{
    qDebug() << "Override the onUpdate method, dummy!";
}

// Updates physics bodies
void PhysicsScene::updateBodies()
{
    QGraphicsItem *item;
    for (b2Body *body = world->GetBodyList(); body; body = body->GetNext())
    {
        item = static_cast<QGraphicsItem*>(body->GetUserData());

        // Update item positions from body data
        if (body->GetType() == b2_dynamicBody)
        {
			qreal itemWidth = item->boundingRect().width();
			qreal itemHeight = item->boundingRect().height();
			timer.stop();
			if (!QRectF(0.0 - itemWidth, 0.0 - itemHeight, sceneRect().width() + itemWidth, sceneRect().height() + itemHeight).contains(item->pos()))
			{
                //world->DestroyBody(body);
                //removeItem(item);
                //delete item;
                //continue;
			}
			timer.start();

			item->setPos(body->GetPosition().x, body->GetPosition().y);
			item->setRotation(body->GetAngle() * 180/b2_pi);
        }
    }
    world->Step(0.25, 8, 4);
//    qDebug() << "Bodies:" << world->GetBodyCount();
}

// Creates a box and links it to a physics body
// http://www.iforce2d.net/b2dtut/bodies
void PhysicsScene::createBox(QRectF rect, QColor line, QColor fill, ItemVal physicsType, bool draggable)
{
    if (world->GetBodyCount() > 20) return;

    // Defines a physics body
    b2BodyDef bodyDef;
    bodyDef.type = (physicsType == Static) ? b2_staticBody : b2_dynamicBody;
    bodyDef.position.Set(rect.x(), rect.y());
    bodyDef.angle = 0;
    b2Body* dynBody = world->CreateBody(&bodyDef);

    // Defines the shape of the body
    b2PolygonShape bodyShape;
    bodyShape.SetAsBox(rect.width() / 2.0, rect.height() / 2.0);

    // Defines a fixture using the previously defined shape
    b2FixtureDef bodyFixtureDef;
    bodyFixtureDef.shape = &bodyShape;
    bodyFixtureDef.density = 1.0;
    dynBody->CreateFixture(&bodyFixtureDef);

    // Create the GraphicsItem (visual part of the body)
    QGraphicsRectItem *item = addRect(QRectF(0.0, 0.0, rect.width(), rect.height()), QPen(line), QBrush(fill));
    item->setTransformOriginPoint(rect.width() / 2.0, rect.height() / 2.0);
    item->setPos(rect.x(), rect.y());

    // TODO: Make sure setting all of these is still necessary
    item->setData(Type, physicsType);
    item->setData(Bounds, rect);
    item->setData(Draggable, draggable);

    // Store the item in the body for easier updating (Yay!)
    dynBody->SetUserData(item);
}

// Creates a Gate from the sprite sheet and links it to a physics body
// http://www.iforce2d.net/b2dtut/bodies
void PhysicsScene::createGate(const QString& resourceName, QRectF rect, QColor line, QColor fill, ItemVal physicsType, bool draggable)
{
    if (world->GetBodyCount() > 20) return;

    // Defines a physics body
    b2BodyDef bodyDef;
    bodyDef.type = (physicsType == Static) ? b2_staticBody : b2_dynamicBody;
    bodyDef.position.Set(rect.x(), rect.y());
    bodyDef.angle = 0;
    b2Body* dynBody = world->CreateBody(&bodyDef);

    // Defines the shape of the body
    b2PolygonShape bodyShape;
    bodyShape.SetAsBox(rect.width() / 2.0, rect.height() / 2.0);

    // Defines a fixture using the previously defined shape
    b2FixtureDef bodyFixtureDef;
    bodyFixtureDef.shape = &bodyShape;
    bodyFixtureDef.density = 1.0;
    dynBody->CreateFixture(&bodyFixtureDef);

    // Create the GraphicsItem (visual part of the body)
    QPixmap gate = QPixmap(resourceName);
    QGraphicsPixmapItem *item = addPixmap(gate);
    item->setTransformOriginPoint(rect.width() / 2.0, rect.height() / 2.0);
    item->setPos(rect.x(), rect.y());

    // TODO: Make sure setting all of these is still necessary
    item->setData(Type, physicsType);
    item->setData(Bounds, rect);
    item->setData(Draggable, draggable);

    // Store the item in the body for easier updating (Yay!)
    dynBody->SetUserData(item);
}

// Sets the position of a body (and by extension, an item)
void PhysicsScene::setItemPos(QGraphicsItem *item, QPointF pos)
{
    QGraphicsItem *temp;
    if (item->data(Draggable).toBool())
    {
        for (b2Body *body = world->GetBodyList(); body; body = body->GetNext())
        {
            // Grab the GraphicsItem that was stored as user data in the body
            temp = static_cast<QGraphicsItem*>(body->GetUserData());
            if (temp == item)
            {
//                b2Vec2 displacement = body->GetPosition() - body->GetWorldCenter();
                body->SetTransform(b2Vec2(pos.x(), pos.y()), body->GetAngle());
//                body->SetTransform(b2Vec2(pos.x() + displacement.x, pos.y() + displacement.y), body->GetAngle());
                body->SetAwake(true);
            }
        }
        item->setPos(pos);
    }
}

// Intercept events from the GraphicsView and do things with them.
bool PhysicsScene::eventFilter(QObject *watched, QEvent *event)
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
        for (b2Body *body = world->GetBodyList(); body; body = body->GetNext())
        {
            QGraphicsItem *temp = static_cast<QGraphicsItem*>(body->GetUserData());
            body->SetTransform(b2Vec2(temp->pos().x(),
                                      temp->pos().y()),
                               body->GetAngle());
        }
        timer.start();
    }

    // Passes the event to be handled in the default manner
    return QGraphicsScene::eventFilter(watched, event);
}
