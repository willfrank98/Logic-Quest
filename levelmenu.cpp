#include "levelmenu.h"
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

LevelMenu::LevelMenu()
{

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
    QPushButton* levelOneEasyButton = new QPushButton();
    levelOneEasyButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.2, 70, 50));
    levelOneEasyButton->setText("1");
    levelOneEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: green;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelOneEasyProxy = addWidget(levelOneEasyButton);
    levelOneEasyProxy->setZValue(10.0);

    QPushButton* levelTwoEasyButton = new QPushButton();
    levelTwoEasyButton->setGeometry(QRect(sceneRect().width()*0.25, sceneRect().height()*0.2, 70, 50));
    levelTwoEasyButton->setText("2");
    levelTwoEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: green;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelTwoEasyProxy = addWidget(levelTwoEasyButton);
    levelTwoEasyProxy->setZValue(10.0);

    QPushButton* levelThreeEasyButton = new QPushButton();
    levelThreeEasyButton->setGeometry(QRect(sceneRect().width()*0.45, sceneRect().height()*0.2, 70, 50));
    levelThreeEasyButton->setText("3");
    levelThreeEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: green;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelThreeEasyProxy = addWidget(levelThreeEasyButton);
    levelThreeEasyProxy->setZValue(10.0);

    QPushButton* levelFourEasyButton = new QPushButton();
    levelFourEasyButton->setGeometry(QRect(sceneRect().width()*0.65, sceneRect().height()*0.2, 70, 50));
    levelFourEasyButton->setText("4");
    levelFourEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: green;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelFourEasyProxy = addWidget(levelFourEasyButton);
    levelFourEasyProxy->setZValue(10.0);

    QPushButton* levelFiveEasyButton = new QPushButton();
    levelFiveEasyButton->setGeometry(QRect(sceneRect().width()*0.85, sceneRect().height()*0.2, 70, 50));
    levelFiveEasyButton->setText("5");
    levelFiveEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: green;"
                                       "color: white;"
                                       "font-size: 16px;"
                                      "}");
    levelFiveEasyProxy = addWidget(levelFiveEasyButton);
    levelFiveEasyProxy->setZValue(10.0);

    /* Header for the Medium levels */
    QGraphicsTextItem *medium = addText("Medium", font);
    medium->setPos(sceneRect().width() / 2.0 - medium->boundingRect().width()/2.0, sceneRect().height()*0.35);

    /* Set the position, width, height, and color for MEDIUM buttons*/
    QPushButton* levelOneMediumButton = new QPushButton();
    levelOneMediumButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.45, 70, 50));
    levelOneMediumButton->setText("1");
    levelOneMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: blue;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelOneMediumProxy = addWidget(levelOneMediumButton);
    levelOneMediumProxy->setZValue(10.0);

    QPushButton* levelTwoMediumButton = new QPushButton();
    levelTwoMediumButton->setGeometry(QRect(sceneRect().width()*0.25, sceneRect().height()*0.45, 70, 50));
    levelTwoMediumButton->setText("2");
    levelTwoMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: blue;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelTwoMediumProxy = addWidget(levelTwoMediumButton);
    levelTwoMediumProxy->setZValue(10.0);

    QPushButton* levelThreeMediumButton = new QPushButton();
    levelThreeMediumButton->setGeometry(QRect(sceneRect().width()*0.45, sceneRect().height()*0.45, 70, 50));
    levelThreeMediumButton->setText("3");
    levelThreeMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: blue;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelThreeMediumProxy = addWidget(levelThreeMediumButton);
    levelThreeMediumProxy->setZValue(10.0);

    QPushButton* levelFourMediumButton = new QPushButton();
    levelFourMediumButton->setGeometry(QRect(sceneRect().width()*0.65, sceneRect().height()*0.45, 70, 50));
    levelFourMediumButton->setText("4");
    levelFourMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: blue;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelFourMediumProxy = addWidget(levelFourMediumButton);
    levelFourMediumProxy->setZValue(10.0);

    QPushButton* levelFiveMediumButton = new QPushButton();
    levelFiveMediumButton->setGeometry(sceneRect().width()*0.85, sceneRect().height()*0.45, 70, 50);
    levelFiveMediumButton->setText("5");
    levelFiveMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: blue;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelFiveMediumProxy = addWidget(levelFiveMediumButton);
    levelFiveMediumProxy->setZValue(10.0);

    /* Header for the Hard levels */
    QGraphicsTextItem *hard = addText("Hard", font);
    hard->setPos(sceneRect().width() / 2.0 - hard->boundingRect().width()/2.0, sceneRect().height()*0.6);

    /* Set the position, width, height, and color for HARD buttons*/
    QPushButton* levelOneHardButton = new QPushButton();
    levelOneHardButton->setGeometry(sceneRect().width()*0.05, sceneRect().height()*0.7, 70, 50);
    levelOneHardButton->setText("1");
    levelOneHardButton->setStyleSheet("QPushButton {"
                                      "background-color: red;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelOneHardProxy = addWidget(levelOneHardButton);
    levelOneHardProxy->setZValue(10.0);

    QPushButton* levelTwoHardButton = new QPushButton();
    levelTwoHardButton->setGeometry(sceneRect().width()*0.25, sceneRect().height()*0.7, 70, 50);
    levelTwoHardButton->setText("2");
    levelTwoHardButton->setStyleSheet("QPushButton {"
                                      "background-color: red;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelTwoHardProxy = addWidget(levelTwoHardButton);
    levelTwoHardProxy->setZValue(10.0);

    QPushButton* levelThreeHardButton = new QPushButton();
    levelThreeHardButton->setGeometry(sceneRect().width()*0.45, sceneRect().height()*0.7, 70, 50);
    levelThreeHardButton->setText("3");
    levelThreeHardButton->setStyleSheet("QPushButton {"
                                      "background-color: red;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelThreeHardProxy = addWidget(levelThreeHardButton);
    levelThreeHardProxy->setZValue(10.0);

    QPushButton* levelFourHardButton = new QPushButton();
    levelFourHardButton->setGeometry(sceneRect().width()*0.65, sceneRect().height()*0.7, 70, 50);
    levelFourHardButton->setText("4");
    levelFourHardButton->setStyleSheet("QPushButton {"
                                      "background-color: red;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelFourHardProxy = addWidget(levelFourHardButton);
    levelFourHardProxy->setZValue(10.0);

    QPushButton* levelFiveHardButton = new QPushButton();
    levelFiveHardButton->setGeometry(sceneRect().width()*0.85, sceneRect().height()*0.7, 70, 50);
    levelFiveHardButton->setText("5");
    levelFiveHardButton->setStyleSheet("QPushButton {"
                                      "background-color: red;"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "}");
    levelFiveHardProxy = addWidget(levelFiveHardButton);
    levelFiveHardProxy->setZValue(10.0);
}
