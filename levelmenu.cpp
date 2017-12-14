/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * levelmenu.cpp
 */

#include "levelmenu.h"

LevelMenu::LevelMenu()
{

}

void LevelMenu::onInit() {

    QFont font = QFont("Helvetica");
    font.setPointSize(24);


    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/sounds/ThroneRoom.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->setCurrentIndex(1);
    musicPlayer = new QMediaPlayer(this);
    musicPlayer->setPlaylist(playlist);
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

    QPixmap *logoPix = new QPixmap(":/images/icons/logoWithoutGates.png");
    QGraphicsPixmapItem *pixItem = addPixmap(*logoPix);
    pixItem->setScale(0.5);
    pixItem->setPos(pixItem->boundingRect().width() * 1.60, 40);


    /* Header for the Easy levels */
    //QGraphicsTextItem *easy = addText("EASY", font);
    QPixmap *easyPix = new QPixmap(":/images/icons/Easy.png");
    QGraphicsPixmapItem *easyItem = addPixmap(*easyPix);
    easyItem->setScale(0.5);
    easyItem->setPos(sceneRect().width() / 2.0 - easyItem->boundingRect().width()/4.0, sceneRect().height()*0.1);

    /* Set the position, width, height, and color for EASY buttons*/
    QPushButton* levelOneEasyButton = new QPushButton();
    levelOneEasyButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.2, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelOneEasyButton->setIcon(QIcon(":/images/icons/One.png"));
    levelOneEasyButton->setIconSize(QSize(64,64));
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
    levelTwoEasyButton->setIcon(QIcon(":/images/icons/Two.png"));
    levelTwoEasyButton->setIconSize(QSize(64,64));
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
    levelThreeEasyButton->setIcon(QIcon(":/images/icons/Three.png"));
    levelThreeEasyButton->setIconSize(QSize(64,64));
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
    levelFourEasyButton->setIcon(QIcon(":/images/icons/Four.png"));
    levelFourEasyButton->setIconSize(QSize(64,64));
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
    levelFiveEasyButton->setIcon(QIcon(":/images/icons/Five.png"));
    levelFiveEasyButton->setIconSize(QSize(64,64));
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

    QPixmap *mediumPix = new QPixmap(":/images/icons/Medium.png");
    QGraphicsPixmapItem *mediumItem = addPixmap(*mediumPix);
    mediumItem->setScale(0.5);
    mediumItem->setPos(sceneRect().width() / 2.0 - mediumItem->boundingRect().width()/4.0, sceneRect().height()*0.35);

    /* Set the position, width, height, and color for MEDIUM buttons*/
    QPushButton* levelOneMediumButton = new QPushButton();
    levelOneMediumButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.45, sceneRect().width()*0.1, sceneRect().height()*0.12));
    levelOneMediumButton->setIcon(QIcon(":/images/icons/One.png"));
    levelOneMediumButton->setIconSize(QSize(64,64));
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
    levelTwoMediumButton->setIcon(QIcon(":/images/icons/Two.png"));
    levelTwoMediumButton->setIconSize(QSize(64,64));
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
    levelThreeMediumButton->setIcon(QIcon(":/images/icons/Three.png"));
    levelThreeMediumButton->setIconSize(QSize(64,64));
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
    levelFourMediumButton->setIcon(QIcon(":/images/icons/Four.png"));
    levelFourMediumButton->setIconSize(QSize(64,64));
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
    levelFiveMediumButton->setIcon(QIcon(":/images/icons/Five.png"));
    levelFiveMediumButton->setIconSize(QSize(64,64));
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
    QPixmap *hardPix = new QPixmap(":/images/icons/Hard.png");
    QGraphicsPixmapItem *hardItem = addPixmap(*hardPix);
    hardItem->setScale(0.5);
    hardItem->setPos(sceneRect().width() / 2.0 - hardItem->boundingRect().width()/4.0, sceneRect().height()*0.6);

    /* Set the position, width, height, and color for HARD buttons*/
    QPushButton* levelOneHardButton = new QPushButton();
    levelOneHardButton->setGeometry(sceneRect().width()*0.05, sceneRect().height()*0.7, sceneRect().width()*0.1, sceneRect().height()*0.12);
    levelOneHardButton->setIcon(QIcon(":/images/icons/One.png"));
    levelOneHardButton->setIconSize(QSize(64,64));
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
    levelTwoHardButton->setIcon(QIcon(":/images/icons/Two.png"));
    levelTwoHardButton->setIconSize(QSize(64,64));
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
    levelThreeHardButton->setIcon(QIcon(":/images/icons/Three.png"));
    levelThreeHardButton->setIconSize(QSize(64,64));
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
    levelFourHardButton->setIcon(QIcon(":/images/icons/Four.png"));
    levelFourHardButton->setIconSize(QSize(64,64));
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
    levelFiveHardButton->setIcon(QIcon(":/images/icons/Five.png"));
    levelFiveHardButton->setIconSize(QSize(64,64));
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
    connect(levelOneEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("easy1"));}, Qt::QueuedConnection);
    connect(levelTwoEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("easy2"));}, Qt::QueuedConnection);
    connect(levelThreeEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("easy3"));}, Qt::QueuedConnection);
    connect(levelFourEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("easy4"));}, Qt::QueuedConnection);
    connect(levelFiveEasyButton, &QPushButton::clicked, this, [=](){emit(changeScene("easy5"));}, Qt::QueuedConnection);

    /*All medium level button connections (defaults to tutorial scene for now)*/
    connect(levelOneMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("medium1"));}, Qt::QueuedConnection);
    connect(levelTwoMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("medium2"));}, Qt::QueuedConnection);
    connect(levelThreeMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("medium3"));}, Qt::QueuedConnection);
    connect(levelFourMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("medium4"));}, Qt::QueuedConnection);
    connect(levelFiveMediumButton, &QPushButton::clicked, this, [=](){emit(changeScene("medium5"));}, Qt::QueuedConnection);

    /*All hard level button connections (defaults to tutorial scene for now)*/
    connect(levelOneHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("hard1"));}, Qt::QueuedConnection);
    connect(levelTwoHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("hard2"));}, Qt::QueuedConnection);
    connect(levelThreeHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("hard3"));}, Qt::QueuedConnection);
    connect(levelFourHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("hard4"));}, Qt::QueuedConnection);
    connect(levelFiveHardButton, &QPushButton::clicked, this, [=](){emit(changeScene("hard5"));}, Qt::QueuedConnection);

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
