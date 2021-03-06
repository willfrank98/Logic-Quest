/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * sceneholder.h
 */

#ifndef SCENEHOLDER_H
#define SCENEHOLDER_H

#include "titlescene.h"
#include "levelmenu.h"
#include "helpscene.h"

class SceneHolder
{
public:
    SceneHolder();
    QGraphicsScene* getScene(QString sceneName);

private:
};

#endif // SCENEHOLDER_H
