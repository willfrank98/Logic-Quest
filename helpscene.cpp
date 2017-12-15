#include "helpscene.h"

HelpScene::HelpScene()
{

}

void HelpScene::onInit()
{

    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/sounds/ReyTheme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->setCurrentIndex(1);
    musicPlayer = new QMediaPlayer(this);
    musicPlayer->setPlaylist(playlist);
    musicPlayer->setVolume(75);
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

    QPushButton* andGateButton = new QPushButton();
    andGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .1, sceneRect().width() * .30, sceneRect().height() * .10));
    andGateButton->setIcon(QIcon(":/images/icons/And.png"));
    andGateButton->setIconSize(QSize(70,70));
    andGateButton->setAttribute(Qt::WA_TranslucentBackground);
    andGateButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(68, 89, 99);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(31, 65, 81);"
                                      "}");
    andGateProxy = addWidget(andGateButton);
    andGateProxy->setZValue(10.0);

    QPushButton* nandGateButton = new QPushButton();
    nandGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .25, sceneRect().width() * .30, sceneRect().height() * .10));
    nandGateButton->setIcon(QIcon(":/images/icons/Nand.png"));
    nandGateButton->setIconSize(QSize(90,90));
    nandGateButton->setAttribute(Qt::WA_TranslucentBackground);
    nandGateButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(68, 89, 99);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(31, 65, 81);"
                                      "}");
    nandGateProxy = addWidget(nandGateButton);
    nandGateProxy-> setZValue(10.0);

    QPushButton* orGateButton = new QPushButton();
    orGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .4, sceneRect().width() * .30, sceneRect().height() * .10));
    orGateButton->setIcon(QIcon(":/images/icons/Or.png"));
    orGateButton->setIconSize(QSize(48,48));
    orGateButton->setAttribute(Qt::WA_TranslucentBackground);
    orGateButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(68, 89, 99);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(31, 65, 81);"
                                      "}");
    orGateProxy = addWidget(orGateButton);
    orGateProxy-> setZValue(10.0);

    QPushButton* norGateButton = new QPushButton();
    norGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .55, sceneRect().width() * .30, sceneRect().height() * .10));
    norGateButton->setIcon(QIcon(":/images/icons/Nor.png"));
    norGateButton->setIconSize(QSize(70,70));
    norGateButton->setAttribute(Qt::WA_TranslucentBackground);
    norGateButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(68, 89, 99);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(31, 65, 81);"
                                      "}");
    norGateProxy = addWidget(norGateButton);
    norGateProxy-> setZValue(10.0);

    QPushButton* xorGateButton = new QPushButton();
    xorGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .7, sceneRect().width() * .30, sceneRect().height() * .10));
    xorGateButton->setIcon(QIcon(":/images/icons/Xor.png"));
    xorGateButton->setIconSize(QSize(70,70));
    xorGateButton->setAttribute(Qt::WA_TranslucentBackground);
    xorGateButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(68, 89, 99);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(31, 65, 81);"
                                      "}");
    xorGateProxy = addWidget(xorGateButton);
    xorGateProxy-> setZValue(10.0);

    QPushButton* notGateButton = new QPushButton();
    notGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .85, sceneRect().width() * .30, sceneRect().height() * .10));
    notGateButton->setIcon(QIcon(":/images/icons/Not.png"));
    notGateButton->setIconSize(QSize(70,70));
    notGateButton->setAttribute(Qt::WA_TranslucentBackground);
    notGateButton->setStyleSheet("QPushButton {"
                                      "background-color: rgb(68, 89, 99);"
                                      "color: white;"
                                      "font-size: 16px;"
                                      "border-style: solid;"
                                      "border-radius: 10px;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: rgb(31, 65, 81);"
                                      "}");
    notGateProxy = addWidget(notGateButton);
    notGateProxy-> setZValue(10.0);

    /* Draw the ground on to this scene exactly like the title scene*/
    createBox(QRectF(0.0, sceneRect().height() - 16.0, sceneRect().width(), 16.0),
              QColor(0, 0, 0), QColor(18,127,155));

    /* Back button connection to link back to main menu */
    connect(backButton, &QPushButton::clicked, this, [=](){emit(changeScene("title"));}, Qt::QueuedConnection);
}
