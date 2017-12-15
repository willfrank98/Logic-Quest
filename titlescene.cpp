/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * titlescene.cpp
 */

#include "titlescene.h"

// Simple example of a title scene
TitleScene::TitleScene()
{

}

// This gets run when the scene is first shown
void TitleScene::onInit()
{
    // Create a static box representing the ground
    // Just gonna leave this enabled until the sprite loading is working
    createBox(QRectF(0.0, sceneRect().height() - 16.0, sceneRect().width(), 16.0),
              QColor(0, 0, 0), QColor(18,127,155));

    //Logo
    QPixmap *logoPix = new QPixmap(":/images/icons/mainLogo.png");
    QGraphicsPixmapItem *pixItem = addPixmap(*logoPix);
    pixItem->setPos(sceneRect().width()/2.0 - pixItem->boundingRect().width()/2.0, 0);


    //Intro music.
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/sounds/Africa.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->setCurrentIndex(1);
    musicPlayer = new QMediaPlayer(this);
    musicPlayer->setPlaylist(playlist);
    musicPlayer->setVolume(50);
    if(enableMusic) musicPlayer->play();

    soundEffect = new QMediaPlayer;
    soundEffect->setMedia(QUrl("qrc:/sounds/Photon.mp3"));

    // Creates a vector that contains a pixmap of each logic gate.
    logicGatesPM = sl->getSprites(":/images/sprites/gatesSheet.png", QSize(64, 64)).toVector();

    // TODO may not need entire sheet?
    // Also help scene
    // Creates a vector that contains a pixmap of the robo
    roboBlocksPM = sl->getSprites(":/images/sprites/da1t_driving.png", QSize(64, 64)).toVector();

    // places robo guide on screen, in bottom left.
    mascot = createSprite(roboBlocksPM[mascotFrame] , QRectF(8, sceneRect().height() - 128, 128.0, 128.0),
              QColor(0, 0, 0, 0), QColor(0, 0, 0, 0), Dynamic);

    //Sound Enable/Disbale Icon.
    QPixmap *soundPix = new QPixmap(":/images/icons/EnableSound.png");
    if(!enableMusic) soundPix = new QPixmap(":/images/icons/DisableSound.png");
    soundItem = new QIcon(*soundPix);
    soundButton = new QPushButton();
    soundButton->setGeometry(QRect(sceneRect().width() * .80, sceneRect().height() * .81, sceneRect().width() * .10, sceneRect().height() * .10));
    soundButton->setAttribute(Qt::WA_TranslucentBackground);
    soundButton->setIcon(*soundItem);
    soundButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    soundButtonProxy = addWidget(soundButton);
    soundButtonProxy->setZValue(10.0);

    //QPixmap *helpPix = new QPixmap(":/images/icons/Help.png");
    QPushButton *helpButton = new QPushButton();
    helpButton->setGeometry(QRect(sceneRect().width() * .80, sceneRect().height() * .69, sceneRect().width() * .10, sceneRect().height() * .10));
    helpButton->setIcon(QIcon(":/images/icons/Help.png"));
    helpButton->setIconSize(QSize(70,70));
    helpButton->setAttribute(Qt::WA_TranslucentBackground);
    helpButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    helpButtonProxy = addWidget(helpButton);
    helpButtonProxy->setZValue(10.0);


    //Sets up menu buttons
    QPushButton *startButton = new QPushButton();
    startButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .45, sceneRect().width() * .30, sceneRect().height() * .10));
    startButton->setIcon(QIcon(":/images/icons/StartGame.png"));
    startButton->setIconSize(QSize(180,180));
    startButton->setAttribute(Qt::WA_TranslucentBackground);
    startButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    startButtonProxy = addWidget(startButton);
    startButtonProxy->setZValue(10.0);  // Makes the buttons appear in front of other things

    QPushButton *levelSelectButton = new QPushButton();
    levelSelectButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .57, sceneRect().width() * .30, sceneRect().height() * .10));
    levelSelectButton->setIcon(QIcon(":/images/icons/LevelSelect.png"));
    levelSelectButton->setIconSize(QSize(195,195));
    levelSelectButton->setAttribute(Qt::WA_TranslucentBackground);
    levelSelectButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    levelSelectButtonProxy = addWidget(levelSelectButton);
    levelSelectButtonProxy->setZValue(10.0);

    QPushButton *optionsButton = new QPushButton();
    optionsButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .69, sceneRect().width() * .30, sceneRect().height() * .10));
    optionsButton->setIcon(QIcon(":/images/icons/Options.png"));
    optionsButton->setIconSize(QSize(120,120));
    optionsButton->setAttribute(Qt::WA_TranslucentBackground);
    optionsButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    optionsButtonProxy = addWidget(optionsButton);
    optionsButtonProxy->setZValue(10.0);

    QPushButton *exitButton = new QPushButton();
    exitButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .81, sceneRect().width() * .30, sceneRect().height() * .10));
    exitButton->setIcon(QIcon(":/images/icons/Exit.png"));
    exitButton->setIconSize(QSize(64,64));
    exitButton->setAttribute(Qt::WA_TranslucentBackground);
    exitButton->setStyleSheet("QPushButton {"
                               "background-color: rgb(68, 89, 99);"
                               "color: white;"
                               "font-size: 16px;"
                               "border-style: solid;"
                               "border-radius: 10px;"
                               "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(31, 65, 81);"
                              "}");
    exitButtonProxy = addWidget(exitButton);
    exitButtonProxy->setZValue(10.0);

    //Connects menu buttons
    connect(startButton, &QPushButton::clicked, this, [=](){tutorialMessage(); emit(changeScene(":/levels/tutorial1.txt"));}, Qt::QueuedConnection);
    connect(levelSelectButton, &QPushButton::clicked, this, [=](){emit(changeScene("levelmenu"));}, Qt::QueuedConnection);
    connect(optionsButton, &QPushButton::clicked, this, [=](){emit(changeScene("options"));}, Qt::QueuedConnection);
    connect(exitButton, &QPushButton::clicked, this, [=](){emit(endProgram());}, Qt::QueuedConnection);
    connect(helpButton, &QPushButton::clicked, this, [=](){emit(changeScene("helpscene"));}, Qt::QueuedConnection);
    connect(soundButton, &QPushButton::clicked, this, &TitleScene::enableDisableSound, Qt::QueuedConnection);

    connect(startButton, &QPushButton::clicked, this, &TitleScene::endMusic);
    connect(levelSelectButton, &QPushButton::clicked, this, &TitleScene::endMusic);
    connect(optionsButton, &QPushButton::clicked, this, &TitleScene::endMusic);
    connect(exitButton, &QPushButton::clicked, this, &TitleScene::endMusic);
    connect(helpButton, &QPushButton::clicked, this, &TitleScene::endMusic);

    //connect(startButton, &QPushButton::clicked, this, &TitleScene::tutorialMessage, Qt::QueuedConnection);
}

// This gets run every 'tick'
void TitleScene::onUpdate(qreal delta)
{
    //generates a random position to place the box
    int pos = qrand()%(int)sceneRect().width();
    // Drops a gate every 50 ticks
    // A tick is the length of the 'timer' interval in the BasicScene/PhysicsScene
    if (tickCounter > 50)
    {
        // generates a random index used to grab a pixmap.
        createSprite(logicGatesPM[lgIndex] , QRectF(pos, 8.0, 64.0, 64.0),
                  QColor(0, 0, 0, 0), QColor(0, 0, 0, 0), Dynamic);
        tickCounter = 0;
        lgIndex++;
        if(lgIndex > 5) {
            lgIndex = 0;
        }
    }

    if (tickCounter % 5 == 0 && mascot != nullptr)
    {
        if (mascotFrame == roboBlocksPM.size()) mascotFrame = 0;
        ((QGraphicsPixmapItem*)mascot)->setPixmap(roboBlocksPM[mascotFrame++].scaled(128, 128));
//        setItemPos(mascot, QPointF(mascot->pos().x() + 10.0, mascot->pos().y()));
    }
    tickCounter++;
}

//Handles the enabling and disabling of the title scene sound.
void TitleScene::enableDisableSound() {

    if(enableMusic) {
    QPixmap *soundPix = new QPixmap(":/images/icons/DisableSound.png");
    soundItem = new QIcon(*soundPix);
    soundButton->setIcon(*soundItem);
    musicPlayer->stop();
    enableMusic = false;
    }
    else {
    QPixmap *soundPix = new QPixmap(":/images/icons/EnableSound.png");
        soundItem = new QIcon(*soundPix);
        soundButton->setIcon(*soundItem);
        musicPlayer->play();
        enableMusic = true;
    }
}

//Ends music when user exits Scene
void TitleScene::endMusic()
{
    if(enableMusic)
    soundEffect->play();
    musicPlayer->stop();
}

void TitleScene::tutorialMessage()
{
    QMessageBox mbox;
    mbox.setStyleSheet(QString::fromUtf8("QMessageBox {"
                                         "background-color: rgb(35, 45, 51);"
                                         "color: white;"
                                         "}"
                                         "QMessageBox QLabel {"
                                         "color: white;"
                                         "}"
                                         "QMessageBox QPushButton {"
                                         "background-color: rgb(68, 89, 99);"
                                         "color: white;"
                                         "width: 50px;"
                                         "height: 25px;"
                                         "border-radius: 5px;"
                                         "}"
                                         "QMessageBox QPushButton:pressed {"
                                         "background-color: rgb(31, 65, 81);"
                                         "}"));
    mbox.setText("The next few levels are tutorial levels to get you aquainted with the different logic gates in the game.  "
                 "Each tutorial level focuses on one gate at a time to help you get a feel for the effects of each gate type.  "
                 "After the tutorial levels you are on your own to solve each puzzle.  "
                 "Good luck and have fun!");
    mbox.exec();
}

void TitleScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        musicPlayer->stop();
        emit changeScene("levelmenu");
    }
}
