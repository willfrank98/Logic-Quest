#include "levelmenu.h"
#include <QGraphicsItem>

LevelMenu::LevelMenu()
{
    addItem(&levelOneEasy);
    addItem(&levelTwoEasy);
    addItem(&levelThreeEasy);
    addItem(&levelFourEasy);
    addItem(&levelFiveEasy);

    addItem(&levelOneMedium);
    addItem(&levelTwoMedium);
    addItem(&levelThreeMedium);
    addItem(&levelFourMedium);
    addItem(&levelFiveMedium);

    addItem(&levelOneHard);
    addItem(&levelTwoHard);
    addItem(&levelThreeHard);
    addItem(&levelFourHard);
    addItem(&levelFiveHard);
}

void LevelMenu::onUpdate(qreal delta) {


}

void LevelMenu::onInit() {

    QFont font = QFont("Helvetica");
    font.setPointSize(24);

    /* Header for the Easy levels */
    QGraphicsTextItem *easy = addText("Easy", font);
    easy->setPos(sceneRect().width() / 2.0 - easy->boundingRect().width()/2.0, sceneRect().height()*0.1);

    /* Set the position, width, height, and color for EASY buttons*/
    levelOneEasy.setRect(sceneRect().width()*0.05, sceneRect().height()*0.2, 70, 50);
    levelOneEasy.setBrush(Qt::green);
    levelTwoEasy.setRect(sceneRect().width()*0.25, sceneRect().height()*0.2, 70, 50);
    levelTwoEasy.setBrush(Qt::green);
    levelThreeEasy.setRect(sceneRect().width()*0.45, sceneRect().height()*0.2, 70, 50);
    levelThreeEasy.setBrush(Qt::green);
    levelFourEasy.setRect(sceneRect().width()*0.65, sceneRect().height()*0.2, 70, 50);
    levelFourEasy.setBrush(Qt::green);
    levelFiveEasy.setRect(sceneRect().width()*0.85, sceneRect().height()*0.2, 70, 50);
    levelFiveEasy.setBrush(Qt::green);

    /* Header for the Medium levels */
    QGraphicsTextItem *medium = addText("Medium", font);
    medium->setPos(sceneRect().width() / 2.0 - medium->boundingRect().width()/2.0, sceneRect().height()*0.35);

    /* Set the position, width, height, and color for MEDIUM buttons*/
    levelOneMedium.setRect(sceneRect().width()*0.05, sceneRect().height()*0.45, 70, 50);
    levelOneMedium.setBrush(Qt::blue);
    levelTwoMedium.setRect(sceneRect().width()*0.25, sceneRect().height()*0.45, 70, 50);
    levelTwoMedium.setBrush(Qt::blue);
    levelThreeMedium.setRect(sceneRect().width()*0.45, sceneRect().height()*0.45, 70, 50);
    levelThreeMedium.setBrush(Qt::blue);
    levelFourMedium.setRect(sceneRect().width()*0.65, sceneRect().height()*0.45, 70, 50);
    levelFourMedium.setBrush(Qt::blue);
    levelFiveMedium.setRect(sceneRect().width()*0.85, sceneRect().height()*0.45, 70, 50);
    levelFiveMedium.setBrush(Qt::blue);

    /* Header for the Hard levels */
    QGraphicsTextItem *hard = addText("Hard", font);
    hard->setPos(sceneRect().width() / 2.0 - hard->boundingRect().width()/2.0, sceneRect().height()*0.6);

    /* Set the position, width, height, and color for HARD buttons*/
    levelOneHard.setRect(sceneRect().width()*0.05, sceneRect().height()*0.7, 70, 50);
    levelOneHard.setBrush(Qt::red);
    levelTwoHard.setRect(sceneRect().width()*0.25, sceneRect().height()*0.7, 70, 50);
    levelTwoHard.setBrush(Qt::red);
    levelThreeHard.setRect(sceneRect().width()*0.45, sceneRect().height()*0.7, 70, 50);
    levelThreeHard.setBrush(Qt::red);
    levelFourHard.setRect(sceneRect().width()*0.65, sceneRect().height()*0.7, 70, 50);
    levelFourHard.setBrush(Qt::red);
    levelFiveHard.setRect(sceneRect().width()*0.85, sceneRect().height()*0.7, 70, 50);
    levelFiveHard.setBrush(Qt::red);
}
