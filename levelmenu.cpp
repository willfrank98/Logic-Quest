#include "levelmenu.h"
#include <QGraphicsItem>

LevelMenu::LevelMenu()
{

    QFont font = QFont("Helvetica");
    font.setPointSize(24);

    /* Header for the Easy levels */
    QGraphicsTextItem *easy = addText("Easy", font);
    easy->setPos(sceneRect().width() / 2.0 - easy->boundingRect().width() / 2.0, sceneRect().height()/0.2);

    /* Set the position, width, height, and color for EASY buttons*/
    levelOneEasy.setRect(sceneRect().width()/0.1, sceneRect().height()/0.3, 70, 50);
    levelOneEasy.setBrush(QBrush(Qt::green));
    levelTwoEasy.setRect(sceneRect().width()/0.3, sceneRect().height()/0.3, 70, 50);
    levelTwoEasy.setBrush(QBrush(Qt::green));
    levelThreeEasy.setRect(sceneRect().width()/0.5, sceneRect().height()/0.3, 70, 50);
    levelThreeEasy.setBrush(QBrush(Qt::green));
    levelFourEasy.setRect(sceneRect().width()/0.7, sceneRect().height()/0.3, 70, 50);
    levelFourEasy.setBrush(QBrush(Qt::green));
    levelFiveEasy.setRect(sceneRect().width()/0.9, sceneRect().height()/0.3, 70, 50);
    levelFiveEasy.setBrush(QBrush(Qt::green));

    /* Header for the Medium levels */
    QGraphicsTextItem *medium = addText("Medium", font);
    medium->setPos(sceneRect().width() / 2.0 - easy->boundingRect().width() / 2.0, sceneRect().height()/0.5);

    /* Set the position, width, height, and color for MEDIUM buttons*/
    levelOneMedium.setRect(sceneRect().width()/0.1, sceneRect().height()/0.6, 70, 50);
    levelOneMedium.setBrush(QBrush(Qt::blue));
    levelTwoMedium.setRect(sceneRect().width()/0.3, sceneRect().height()/0.6, 70, 50);
    levelTwoMedium.setBrush(QBrush(Qt::blue));
    levelThreeMedium.setRect(sceneRect().width()/0.5, sceneRect().height()/0.6, 70, 50);
    levelThreeMedium.setBrush(QBrush(Qt::blue));
    levelFourMedium.setRect(sceneRect().width()/0.7, sceneRect().height()/0.6, 70, 50);
    levelFourMedium.setBrush(QBrush(Qt::blue));
    levelFiveMedium.setRect(sceneRect().width()/0.9, sceneRect().height()/0.6, 70, 50);
    levelFiveMedium.setBrush(QBrush(Qt::blue));

    /* Header for the Hard levels */
    QGraphicsTextItem *hard = addText("Hard", font);
    hard->setPos(sceneRect().width() / 2.0 - easy->boundingRect().width() / 2.0, sceneRect().height()/0.75);

    /* Set the position, width, height, and color for HARD buttons*/
    levelOneHard.setRect(sceneRect().width()/0.1, sceneRect().height()/0.85, 70, 50);
    levelOneHard.setBrush(QBrush(Qt::red));
    levelTwoHard.setRect(sceneRect().width()/0.3, sceneRect().height()/0.85, 70, 50);
    levelTwoHard.setBrush(QBrush(Qt::red));
    levelThreeHard.setRect(sceneRect().width()/0.5, sceneRect().height()/0.85, 70, 50);
    levelThreeHard.setBrush(QBrush(Qt::red));
    levelFourHard.setRect(sceneRect().width()/0.7, sceneRect().height()/0.85, 70, 50);
    levelFourHard.setBrush(QBrush(Qt::red));
    levelFiveHard.setRect(sceneRect().width()/0.9, sceneRect().height()/0.85, 70, 50);
    levelFiveHard.setBrush(QBrush(Qt::red));
}

void LevelMenu::onUpdate(qreal delta) {


}
