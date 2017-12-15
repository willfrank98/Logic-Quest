#ifndef HELPSCENE_H
#define HELPSCENE_H
#include "basicscene.h"
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class HelpScene : public BasicScene
{
public:
    HelpScene();
    void onInit();

private: 
    QMediaPlaylist* playlist;
    QMediaPlayer* musicPlayer;

    QGraphicsProxyWidget* backToHomeProxy;
    QGraphicsProxyWidget* andGateProxy;
    QGraphicsProxyWidget* nandGateProxy;
    QGraphicsProxyWidget* orGateProxy;
    QGraphicsProxyWidget* norGateProxy;
    QGraphicsProxyWidget* xorGateProxy;
    QGraphicsProxyWidget* notGateProxy;

};

#endif // HELPSCENE_H
