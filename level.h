/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * level.h
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <gatenode.h>

class Level
{
private:
    bool isComplete;
    QVector<GateNode*> startGates;
    QVector<GateNode*> endGates;
    QVector<GateNode*> gates;
    QVector<int> goals;
    QVector<int> endGateLocations;
    int numCols;
    int numRows;
    QVector<GatePipeTags> layout;
    QVector<int> gateNodeIndex;
    void addGateWithStartGateInput(int gIndex, int sgIndex, int sgValue);
    void addGateWithGateInput(int gIndex, int igIndex);
    void addEndGateWithGateInput(int egIndex, int gIndex);
    GatePipeTags getLayOutEnum(QString str);

public:
    Level();
    Level(QString filename);
    void checkOutputs();
    QVector<int> setGateType(int gateIndex, GateNodeType type);
    QVector<int> getGoals();
    QVector<GatePipeTags> getLayout();
    int getNumColumns();
    int getNumRows();
    int getGateNodeIndex(int layoutIndex);
    QVector<GateNode*> getEndGates();
};

#endif // LEVEL_H
