#include "sceneholder.h"

SceneHolder::SceneHolder()
{

}

// Defines possible scenes to switch between
// This feels like poor design.  If anyone has a better idea, please bring it up.
QGraphicsScene* SceneHolder::getScene(QString sceneName)
{
    if (sceneName.toLower() == "title") return new TitleScene();
	else if (sceneName.toLower() == "tutorial") return new Tutorial();
    else if (sceneName.toLower() == "level1") return new LevelOne();
    else if (sceneName.toLower() == "levelmenu") return new LevelMenu();
    else return nullptr;
}
