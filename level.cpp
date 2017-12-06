/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * level.cpp
 */

#include "level.h"

Level::Level(QVector<GateNode> newInputs, QVector<GateNode> newOutputs, QVector<GateNode> newGates,
             QVector<int> newGoals, int newRowSize, QVector<QString> newLayout)
{
    isComplete = false;
    inputs = newInputs;
    outputs = newOutputs;
    gates = newGates;
    goals = newGoals;
    rowSize = newRowSize;
    layout = newLayout;
}

void Level::checkOutputs()
{
    for (int i = 0; i < goals.size(); i++)
    {
        if(goals[i] != outputs[i].getOutput())
        {
            isComplete = false;
            return;
        }
    }
    isComplete = true;
}

void Level::setGateType(int gateIndex, GateNodeType type)
{
    gates[gateIndex].setGateType(type);
    gates[gateIndex].processGate();
}
