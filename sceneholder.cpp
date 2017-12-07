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
//	int tut1Ins[5] = {-1, -1, 0, -1, -1};
//    QVector<int> tut1Goals;
//    tut1Goals.append(1);
//    QVector<GatePipeTags> tut1Grid;
//    for (int i = 0; i < 25; i++)
//    {
//        if(i % 3 == 0)
//        {
//            tut1Grid.append(UG);
//        }
//        else
//        {
//            tut1Grid.append(NL);
//        }
//    }
//    tut1Grid[1] = WS;
//    tut1Grid[7] = WE;
//    tut1Grid[8] = WE;

    if (sceneName.toLower() == "title") return new TitleScene();
    else if (sceneName.toLower() == "tutorial") return new BasicScene(Level(QString("/levels/tutorial.txt")));
	//else if (sceneName.toLower() == "level1" || sceneName.toLower() == "levelone") return new LevelOne();
    else if (sceneName.toLower() == "levelmenu") return new LevelMenu();
    else return nullptr;
}
