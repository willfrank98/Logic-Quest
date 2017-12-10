/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * sceneholder.cpp
 */

#include "sceneholder.h"

SceneHolder::SceneHolder()
{

}

// Defines possible scenes to switch between
// This feels like poor design.  If anyone has a better idea, please bring it up.
QGraphicsScene* SceneHolder::getScene(QString sceneName)
{
    if (sceneName.toLower() == "title") return new TitleScene();
    else if (sceneName.toLower() == "tutorial") return new BasicScene(Level(QString(":/levels/tutorial.txt")));
    else if (sceneName.toLower() == "tutorial1") return new BasicScene(Level(QString(":/levels/tutorial1.txt")));
    else if (sceneName.toLower() == "tutorial2") return new BasicScene(Level(QString(":/levels/tutorial2.txt")));
    else if (sceneName.toLower() == "tutorial3") return new BasicScene(Level(QString(":/levels/tutorial3.txt")));
    else if (sceneName.toLower() == "tutorial4") return new BasicScene(Level(QString(":/levels/tutorial4.txt")));
    else if (sceneName.toLower() == "tutorial5") return new BasicScene(Level(QString(":/levels/tutorial5.txt")));
    else if (sceneName.toLower() == "tutorial6") return new BasicScene(Level(QString(":/levels/tutorial6.txt")));
    else if (sceneName.toLower() == "levelmenu") return new LevelMenu();
	else if (sceneName.toLower() == "options") return new OptionsScene();
    else return nullptr;
}
