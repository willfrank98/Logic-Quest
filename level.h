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

public:
    Level(QVector<GateNode> newInputs, QVector<GateNode> newOutputs, QVector<GateNode> newGates, QVector<int> newGoals);
    void checkOutputs();
    void setGateType(int gateIndex, GateNodeType type);
    QVector<QString> getLayout();
};

#endif // LEVEL_H
