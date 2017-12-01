#ifndef SCENEHOLDER_H
#define SCENEHOLDER_H

#include "titlescene.h"
#include "tutorial.h"
#include "levelmenu.h"
#include "levelone.h"

class SceneHolder
{
public:
    SceneHolder();
    QGraphicsScene* getScene(QString sceneName);

private:
};

#endif // SCENEHOLDER_H
