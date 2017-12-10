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
    else if (sceneName.toLower() == "levelmenu") return new LevelMenu();
    else if (sceneName.toLower() == "options") return new OptionsScene();
    else return new BasicScene(Level(QString(sceneName)));
}
