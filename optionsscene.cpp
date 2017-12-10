#include "optionsscene.h"

OptionsScene::OptionsScene()
{

}

void OptionsScene::onInit()
{
	QFont font = QFont("Helvetica");
	font.setPointSize(24);

	//draw back button
	QPushButton* backButton = new QPushButton();
	backButton->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.05, 60, 40));
	backButton->setText("Back");
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

	QGraphicsTextItem *easy = addText("Resolution", font);
	easy->setPos(sceneRect().width() / 2.0 - easy->boundingRect().width()/2.0, sceneRect().height()*0.1);


	/* Set the position, width, height, and color for EASY buttons*/
	QPushButton* r600Button = new QPushButton();
	r600Button->setGeometry(QRect(sceneRect().width()*0.05, sceneRect().height()*0.2, 90, 50));
	r600Button->setText("600x480");
	r600Button->setAttribute(Qt::WA_TranslucentBackground);
	r600Button->setStyleSheet("QPushButton {"
									  "background-color: rgb(92, 249, 158);"
									  "color: white;"
									  "font-size: 16px;"
									  "border-style: solid;"
									  "border-radius: 10px;"
									  "}"
									  "QPushButton:pressed {"
									  "background-color: rgb(66, 191, 118);"
									  "}");
	r600x480PRoxy = addWidget(r600Button);
	r600x480PRoxy->setZValue(10.0);

	QPushButton* r1280Button = new QPushButton();
	r1280Button->setGeometry(QRect(sceneRect().width()*0.25, sceneRect().height()*0.2, 90, 50));
	r1280Button->setText("1280x720");
	r1280Button->setAttribute(Qt::WA_TranslucentBackground);
	r1280Button->setStyleSheet("QPushButton {"
									  "background-color: rgb(92, 249, 158);"
									  "color: white;"
									  "font-size: 16px;"
									  "border-style: solid;"
									  "border-radius: 10px;"
									  "}"
									  "QPushButton:pressed {"
									  "background-color: rgb(66, 191, 118);"
									  "}");
	r1280x720Proxy = addWidget(r1280Button);
	r1280x720Proxy->setZValue(10.0);

	QPushButton* r1366Button = new QPushButton();
	r1366Button->setGeometry(QRect(sceneRect().width()*0.45, sceneRect().height()*0.2, 90, 50));
	r1366Button->setText("1366x720");
	r1366Button->setAttribute(Qt::WA_TranslucentBackground);
	r1366Button->setStyleSheet("QPushButton {"
									  "background-color: rgb(92, 249, 158);"
									  "color: white;"
									  "font-size: 16px;"
									  "border-style: solid;"
									  "border-radius: 10px;"
									  "}"
									  "QPushButton:pressed {"
									  "background-color: rgb(66, 191, 118);"
									  "}");
	r1366x720Proxy = addWidget(r1366Button);
	r1366x720Proxy->setZValue(10.0);

	QPushButton* r1920Button = new QPushButton();
	r1920Button->setGeometry(QRect(sceneRect().width()*0.65, sceneRect().height()*0.2, 90, 50));
	r1920Button->setText("1920x1080");
	r1920Button->setAttribute(Qt::WA_TranslucentBackground);
	r1920Button->setStyleSheet("QPushButton {"
									  "background-color: rgb(92, 249, 158);"
									  "color: white;"
									  "font-size: 16px;"
									  "border-style: solid;"
									  "border-radius: 10px;"
									  "}"
									  "QPushButton:pressed {"
									  "background-color: rgb(66, 191, 118);"
									  "}");
	r1920x1080Proxy = addWidget(r1920Button);
	r1920x1080Proxy->setZValue(10.0);

	QPushButton* rFullscreenButton = new QPushButton();
	rFullscreenButton->setGeometry(QRect(sceneRect().width()*0.85, sceneRect().height()*0.2, 90, 50));
	rFullscreenButton->setText("Fullscreen");
	rFullscreenButton->setAttribute(Qt::WA_TranslucentBackground);
	rFullscreenButton->setStyleSheet("QPushButton {"
									  "background-color: rgb(92, 249, 158);"
									  "color: white;"
									  "font-size: 16px;"
									  "border-style: solid;"
									  "border-radius: 10px;"
									  "}"
									  "QPushButton:pressed {"
									  "background-color: rgb(66, 191, 118);"
									  "}");
	rFullscreenProxy = addWidget(rFullscreenButton);
	rFullscreenProxy->setZValue(10.0);

	// Back button connection to link back to main menu
	connect(backButton, &QPushButton::clicked, this, [=](){emit(changeScene("title"));}, Qt::QueuedConnection);

	// Handles resolution changes
	connect(resSettings, &QActionGroup::triggered, this, [=](QAction *a){

		// Gets the width and height from the action name
		QString newRes = a->text();
		int width = newRes.split('x').first().toInt();
		int height = newRes.split('x').last().toInt();

		// Just make fullscreen if unable to parse correctly
		if (width == 0 && height == 0)
		{
			setWindowState(Qt::WindowFullScreen);
		}
		else  // Resize things to the desired dimensions
		{
			setWindowState(Qt::WindowNoState);
			resize(width, height);
			setGeometry(QApplication::desktop()->size().width() / 2.0 - size().width() / 2.0,
						QApplication::desktop()->size().height() / 2.0 - size().height() / 2.0,
						size().width(), size().height());
		}
	});
}
