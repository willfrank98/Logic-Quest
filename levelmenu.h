/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * levelmenu.h
 */

#ifndef LEVELMENU_H
#define LEVELMENU_H

#include "basicscene.h"

class LevelMenu : public BasicScene
{
public:
    LevelMenu();
    void onUpdate(qreal delta);
    void onInit();

private:
//    //All easy level buttons
//    QGraphicsRectItem levelOneEasy;
//    QGraphicsRectItem levelTwoEasy;
//    QGraphicsRectItem levelThreeEasy;
//    QGraphicsRectItem levelFourEasy;
//    QGraphicsRectItem levelFiveEasy;

//    //All medium level buttons
//    QGraphicsRectItem levelOneMedium;
//    QGraphicsRectItem levelTwoMedium;
//    QGraphicsRectItem levelThreeMedium;
//    QGraphicsRectItem levelFourMedium;
//    QGraphicsRectItem levelFiveMedium;

//    //All hard level buttons
//    QGraphicsRectItem levelOneHard;
//    QGraphicsRectItem levelTwoHard;
//    QGraphicsRectItem levelThreeHard;
//    QGraphicsRectItem levelFourHard;
//    QGraphicsRectItem levelFiveHard;

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
};

#endif // LEVELMENU_H
