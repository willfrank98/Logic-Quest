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
    QVector<GateNode> inputs;
    QVector<GateNode> outputs;
    QVector<GateNode> gates;
    QVector<int> goals;
    int numCols;
    int numRows;
    QVector<GatePipeTags> layout;
    void addGateWithStartGateInput(int gIndex, int sgIndex, int sgValue);
    void addGateWithGateInput(int gIndex, int igIndex);
    void addEndGateWithGateInput(int egIndex, int gIndex);

public:
    Level(QVector<GateNode> newInputs, QVector<GateNode> newOutputs, QVector<GateNode> newGates,
          QVector<int> newGoals, int newRowSize, QVector<GatePipeTags> newLayout);
    Level(QString filename);
    void checkOutputs();
    void setGateType(int gateIndex, GateNodeType type);
    QVector<int> getGoals();
    QVector<GatePipeTags> getLayout();
    int getNumColumns();
    int getNumRows();
};

#endif // LEVEL_H
