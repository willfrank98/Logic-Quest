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
	int tut1Ins[5] = {-1, -1, 0, -1, -1};
	int tut1Outs[5] = {-1, -1, 1, -1, -1};
	int tut1Grid[25] = {0, 0, 0, 0, 0,
						0, 0, 0, 0, 0,
						0, 0, 0, 0, 0,
						0, 0, 0, 0, 0,
						0, 0, 0, 0, 0};

    if (sceneName.toLower() == "title") return new TitleScene();
	else if (sceneName.toLower() == "tutorial") return new BasicScene(nullptr, 5, 5, tut1Ins, tut1Outs, tut1Grid);
	//else if (sceneName.toLower() == "level1" || sceneName.toLower() == "levelone") return new LevelOne();
    else if (sceneName.toLower() == "levelmenu") return new LevelMenu();
    else return nullptr;
}
