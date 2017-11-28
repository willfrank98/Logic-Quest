#ifndef LEVELONE_H
#define LEVELONE_H

#include <basicscene.h>

class LevelOne : public BasicScene
{
public:
    LevelOne();

    void onInit();
    void onUpdate(qreal delta);
};

#endif // LEVELONE_H
