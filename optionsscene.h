#ifndef OPTIONSSCENE_H
#define OPTIONSSCENE_H

#include "basicscene.h"

class OptionsScene : public BasicScene
{
public:
	OptionsScene();
	void onInit();

private:
	//Back button to redirect to main menu
	QGraphicsProxyWidget* backToHomeProxy;

	//All resolution option proxies
	QGraphicsProxyWidget* r600x480PRoxy;
	QGraphicsProxyWidget* r1280x720Proxy;
	QGraphicsProxyWidget* r1366x720Proxy;
	QGraphicsProxyWidget* r1920x1080Proxy;
	QGraphicsProxyWidget* rFullscreenProxy;
};

#endif // OPTIONSSCENE_H
