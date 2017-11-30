#ifndef LEVELMENU_H
#define LEVELMENU_H

#include "basicscene.h"
#include <QGraphicsItem>

class LevelMenu : public BasicScene
{
public:
    LevelMenu();

private:
    //All easy level buttons
    QGraphicsRectItem levelOneEasy;
    QGraphicsRectItem levelTwoEasy;
    QGraphicsRectItem levelThreeEasy;
    QGraphicsRectItem levelFourEasy;
    QGraphicsRectItem levelFiveEasy;

    //All medium level buttons
    QGraphicsRectItem levelOneMedium;
    QGraphicsRectItem levelTwoMedium;
    QGraphicsRectItem levelThreeMedium;
    QGraphicsRectItem levelFourMedium;
    QGraphicsRectItem levelFiveMedium;

    //All hard level buttons
    QGraphicsRectItem levelOneHard;
    QGraphicsRectItem levelTwoHard;
    QGraphicsRectItem levelThreeHard;
    QGraphicsRectItem levelFourHard;
    QGraphicsRectItem levelFiveHard;
};

#endif // LEVELMENU_H
