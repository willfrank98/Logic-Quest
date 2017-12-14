#include "helpscene.h"

HelpScene::HelpScene()
{

}

void HelpScene::onInit()
{
    QPushButton* andGateButton = new QPushButton();
    andGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .1, sceneRect().width() * .30, sceneRect().height() * .10));
    andGateButton->setText("AND");
    andGateButton->setIconSize(QSize(64,64));
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
    nandGateButton->setText("NAND");
    nandGateButton->setIconSize(QSize(64,64));
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
    orGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .25, sceneRect().width() * .30, sceneRect().height() * .10));
    orGateButton->setText("OR");
    orGateButton->setIconSize(QSize(64,64));
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
    norGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .4, sceneRect().width() * .30, sceneRect().height() * .10));
    norGateButton->setText("NOR");
    norGateButton->setIconSize(QSize(64,64));
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
    xorGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .55, sceneRect().width() * .30, sceneRect().height() * .10));
    xorGateButton->setText("XOR");
    xorGateButton->setIconSize(QSize(64,64));
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
    notGateButton->setGeometry(QRect(sceneRect().width() * .35, sceneRect().height() * .7, sceneRect().width() * .30, sceneRect().height() * .10));
    notGateButton->setText("NOT");
    notGateButton->setIconSize(QSize(64,64));
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

    createBox(QRectF(0.0, sceneRect().height() - 16.0, sceneRect().width(), 16.0),
              QColor(0, 0, 0), QColor(18,127,155));
}
