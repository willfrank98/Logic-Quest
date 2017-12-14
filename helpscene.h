#ifndef HELPSCENE_H
#define HELPSCENE_H
#include "basicscene.h"
#include "physicsscene.h"
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class HelpScene : public BasicScene
{
public:
    HelpScene();
    void onInit();

private:
    QGraphicsProxyWidget* backToHomeProxy;
    QGraphicsProxyWidget* andGateProxy;
    QGraphicsProxyWidget* nandGateProxy;
    QGraphicsProxyWidget* orGateProxy;
    QGraphicsProxyWidget* norGateProxy;
    QGraphicsProxyWidget* xorGateProxy;
    QGraphicsProxyWidget* notGateProxy;

};

#endif // HELPSCENE_H
