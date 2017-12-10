/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * levelmenu.cpp
 */

#include "levelmenu.h"
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

LevelMenu::LevelMenu()
{

}

void LevelMenu::onInit() {

    QFont font = QFont("Helvetica");
    font.setPointSize(24);

    musicPlayer = new QMediaPlayer;
    musicPlayer->setMedia(QUrl("qrc:/sounds/Visager_-_04_-_Factory_Time.mp3"));
    musicPlayer->setVolume(50);
    if(enableMusic) musicPlayer->play();

    QPixmap *backPix = new QPixmap(":/images/icons/Home.png");
    QIcon *backIcon = new QIcon(*backPix);
    QPushButton* backButton = new QPushButton();
    backButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.05, 60, 40));
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


    /* Header for the Easy levels */
    QGraphicsTextItem *easy = addText("EASY", font);
    easy->setPos(sceneRect().width() / 2.0 - easy->boundingRect().width()/2.0, sceneRect().height()*0.1);

    /* Set the position, width, height, and color for EASY buttons*/
    QPushButton* levelOneEasyButton = new QPushButton();
    levelOneEasyButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.2, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelOneEasyButton->setText("1");
    levelOneEasyButton->setAttribute(Qt::WA_TranslucentBackground);
    levelOneEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 249, 158);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(66, 191, 118);"
                                      "}");
    levelOneEasyProxy = addWidget(levelOneEasyButton);
    levelOneEasyProxy->setZValue(10.0);

    QPushButton* levelTwoEasyButton = new QPushButton();
    levelTwoEasyButton->setGeometry(QRect(sceneRect().width()*0.25, sceneRect().height()*0.2, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelTwoEasyButton->setText("2");
    levelTwoEasyButton->setAttribute(Qt::WA_TranslucentBackground);
    levelTwoEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 249, 158);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(66, 191, 118);"
                                      "}");
    levelTwoEasyProxy = addWidget(levelTwoEasyButton);
    levelTwoEasyProxy->setZValue(10.0);

    QPushButton* levelThreeEasyButton = new QPushButton();
    levelThreeEasyButton->setGeometry(QRect(sceneRect().width()*0.45, sceneRect().height()*0.2, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelThreeEasyButton->setText("3");
    levelThreeEasyButton->setAttribute(Qt::WA_TranslucentBackground);
    levelThreeEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 249, 158);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(66, 191, 118);"
                                      "}");
    levelThreeEasyProxy = addWidget(levelThreeEasyButton);
    levelThreeEasyProxy->setZValue(10.0);

    QPushButton* levelFourEasyButton = new QPushButton();
    levelFourEasyButton->setGeometry(QRect(sceneRect().width()*0.65, sceneRect().height()*0.2, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelFourEasyButton->setText("4");
    levelFourEasyButton->setAttribute(Qt::WA_TranslucentBackground);
    levelFourEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 249, 158);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(66, 191, 118);"
                                      "}");
    levelFourEasyProxy = addWidget(levelFourEasyButton);
    levelFourEasyProxy->setZValue(10.0);

    QPushButton* levelFiveEasyButton = new QPushButton();
    levelFiveEasyButton->setGeometry(QRect(sceneRect().width()*0.85, sceneRect().height()*0.2, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelFiveEasyButton->setText("5");
    levelFiveEasyButton->setAttribute(Qt::WA_TranslucentBackground);
    levelFiveEasyButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 249, 158);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(66, 191, 118);"
                                      "}");
    levelFiveEasyProxy = addWidget(levelFiveEasyButton);
    levelFiveEasyProxy->setZValue(10.0);

    /* Header for the Medium levels */
    QGraphicsTextItem *medium = addText("MEDIUM", font);
    medium->setPos(sceneRect().width() / 2.0 - medium->boundingRect().width()/2.0, sceneRect().height()*0.35);

    /* Set the position, width, height, and color for MEDIUM buttons*/
    QPushButton* levelOneMediumButton = new QPushButton();
    levelOneMediumButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.45, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelOneMediumButton->setText("1");
    levelOneMediumButton->setAttribute(Qt::WA_TranslucentBackground);
    levelOneMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 235, 249);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(76, 191, 201)"
                                      "}");
    levelOneMediumProxy = addWidget(levelOneMediumButton);
    levelOneMediumProxy->setZValue(10.0);

    QPushButton* levelTwoMediumButton = new QPushButton();
    levelTwoMediumButton->setGeometry(QRect(sceneRect().width()*0.25, sceneRect().height()*0.45, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelTwoMediumButton->setText("2");
    levelTwoMediumButton->setAttribute(Qt::WA_TranslucentBackground);
    levelTwoMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 235, 249);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(76, 191, 201)"
                                      "}");
    levelTwoMediumProxy = addWidget(levelTwoMediumButton);
    levelTwoMediumProxy->setZValue(10.0);

    QPushButton* levelThreeMediumButton = new QPushButton();
    levelThreeMediumButton->setGeometry(QRect(sceneRect().width()*0.45, sceneRect().height()*0.45, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelThreeMediumButton->setText("3");
    levelThreeMediumButton->setAttribute(Qt::WA_TranslucentBackground);
    levelThreeMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 235, 249);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(76, 191, 201)"
                                      "}");
    levelThreeMediumProxy = addWidget(levelThreeMediumButton);
    levelThreeMediumProxy->setZValue(10.0);

    QPushButton* levelFourMediumButton = new QPushButton();
    levelFourMediumButton->setGeometry(QRect(sceneRect().width()*0.65, sceneRect().height()*0.45, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelFourMediumButton->setText("4");
    levelFourMediumButton->setAttribute(Qt::WA_TranslucentBackground);
    levelFourMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 235, 249);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(76, 191, 201)"
                                      "}");
    levelFourMediumProxy = addWidget(levelFourMediumButton);
    levelFourMediumProxy->setZValue(10.0);

    QPushButton* levelFiveMediumButton = new QPushButton();
    levelFiveMediumButton->setGeometry(sceneRect().width()*0.85, sceneRect().height()*0.45, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelFiveMediumButton->setText("5");
    levelFiveMediumButton->setAttribute(Qt::WA_TranslucentBackground);
    levelFiveMediumButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(92, 235, 249);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(76, 191, 201)"
                                      "}");
    levelFiveMediumProxy = addWidget(levelFiveMediumButton);
    levelFiveMediumProxy->setZValue(10.0);

    /* Header for the Hard levels */
    QGraphicsTextItem *hard = addText("HARD", font);
    hard->setPos(sceneRect().width() / 2.0 - hard->boundingRect().width()/2.0, sceneRect().height()*0.6);

    /* Set the position, width, height, and color for HARD buttons*/
    QPushButton* levelOneHardButton = new QPushButton();
    levelOneHardButton->setGeometry(sceneRect().width()*0.05, sceneRect().height()*0.7, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelOneHardButton->setText("1");
    levelOneHardButton->setAttribute(Qt::WA_TranslucentBackground);
    levelOneHardButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(249, 92, 131);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(188, 69, 99)"
                                      "}");
    levelOneHardProxy = addWidget(levelOneHardButton);
    levelOneHardProxy->setZValue(10.0);

    QPushButton* levelTwoHardButton = new QPushButton();
    levelTwoHardButton->setGeometry(sceneRect().width()*0.25, sceneRect().height()*0.7, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelTwoHardButton->setText("2");
    levelTwoHardButton->setAttribute(Qt::WA_TranslucentBackground);
    levelTwoHardButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(249, 92, 131);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(188, 69, 99)"
                                      "}");
    levelTwoHardProxy = addWidget(levelTwoHardButton);
    levelTwoHardProxy->setZValue(10.0);

    QPushButton* levelThreeHardButton = new QPushButton();
    levelThreeHardButton->setGeometry(sceneRect().width()*0.45, sceneRect().height()*0.7, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelThreeHardButton->setText("3");
    levelThreeHardButton->setAttribute(Qt::WA_TranslucentBackground);
    levelThreeHardButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(249, 92, 131);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(188, 69, 99)"
                                      "}");
    levelThreeHardProxy = addWidget(levelThreeHardButton);
    levelThreeHardProxy->setZValue(10.0);

    QPushButton* levelFourHardButton = new QPushButton();
    levelFourHardButton->setGeometry(sceneRect().width()*0.65, sceneRect().height()*0.7, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelFourHardButton->setText("4");
    levelFourHardButton->setAttribute(Qt::WA_TranslucentBackground);
    levelFourHardButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(249, 92, 131);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(188, 69, 99)"
                                      "}");
    levelFourHardProxy = addWidget(levelFourHardButton);
    levelFourHardProxy->setZValue(10.0);

    QPushButton* levelFiveHardButton = new QPushButton();
    levelFiveHardButton->setGeometry(sceneRect().width()*0.85, sceneRect().height()*0.7, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelFiveHardButton->setText("5");
    levelFiveHardButton->setAttribute(Qt::WA_TranslucentBackground);
    levelFiveHardButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(249, 92, 131);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(188, 69, 99)"
                                      "}");
    levelFiveHardProxy = addWidget(levelFiveHardButton);
    levelFiveHardProxy->setZValue(10.0);

    /* Back button connection to link back to main menu */
    connect(backButton, &QPushButton::clicked, this, [=](){emit(changeScene("title"));}, Qt::QueuedConnection);

    /*All easy level button connections (defaults to tutorial scene for now)*/
    connect(levelOneEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelTwoEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelThreeEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelFourEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelFiveEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);

    /*All medium level button connections (defaults to tutorial scene for now)*/
    connect(levelOneMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelTwoMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelThreeMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelFourMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelFiveMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);

    /*All hard level button connections (defaults to tutorial scene for now)*/
    connect(levelOneHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelTwoHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelThreeHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelFourHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);
    connect(levelFiveHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("tutorial"));}, Qt::QueuedConnection);

    /*Stops music on all buttons*/
    connect(backButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelOneEasyButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelTwoEasyButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelThreeEasyButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelFourEasyButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelFiveEasyButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelOneMediumButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelTwoMediumButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelThreeMediumButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelFourMediumButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelFiveMediumButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelOneHardButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelTwoHardButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelThreeHardButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelFourHardButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
    connect(levelFiveHardButton, &QPushButton::clicked, this, &LevelMenu::endMusic);
}

//Ends music when user exits Scene
void LevelMenu::endMusic() {
    musicPlayer->stop();
}
