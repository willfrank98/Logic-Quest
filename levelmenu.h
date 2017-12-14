/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * levelmenu.h
 */

#ifndef LEVELMENU_H
#define LEVELMENU_H

#include "basicscene.h"
#include "physicsscene.h"
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class LevelMenu : public BasicScene
{
public:
    LevelMenu();
    void onInit();

private:

    QMediaPlaylist* playlist;
    QMediaPlayer *musicPlayer;

    //Back button to redirect to main menu
    QGraphicsProxyWidget* backToHomeProxy;

    //All easy level button proxies
    QGraphicsProxyWidget* levelOneEasyProxy;
    QGraphicsProxyWidget* levelTwoEasyProxy;
    QGraphicsProxyWidget* levelThreeEasyProxy;
    QGraphicsProxyWidget* levelFourEasyProxy;
    QGraphicsProxyWidget* levelFiveEasyProxy;

    //All medium level button proxies
    QGraphicsProxyWidget* levelOneMediumProxy;
    QGraphicsProxyWidget* levelTwoMediumProxy;
    QGraphicsProxyWidget* levelThreeMediumProxy;
    QGraphicsProxyWidget* levelFourMediumProxy;
    QGraphicsProxyWidget* levelFiveMediumProxy;

    //All hard level button proxies
    QGraphicsProxyWidget* levelOneHardProxy;
    QGraphicsProxyWidget* levelTwoHardProxy;
    QGraphicsProxyWidget* levelThreeHardProxy;
    QGraphicsProxyWidget* levelFourHardProxy;
    QGraphicsProxyWidget* levelFiveHardProxy;

    void endMusic();
};

#endif // LEVELMENU_H
