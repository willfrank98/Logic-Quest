/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * level.cpp
 */

#include "level.h"
#include <QFile>
#include <QDebug>

Level::Level(QVector<GateNode> newInputs, QVector<GateNode> newOutputs, QVector<GateNode> newGates,
             QVector<int> newGoals, int newRowSize, QVector<GatePipeTags> newLayout)
{
    isComplete = false;
    inputs = newInputs;
    outputs = newOutputs;
    gates = newGates;
    goals = newGoals;
    numCols = newRowSize;
    layout = newLayout;
}

Level::Level(QString filename)
{
    QFile file(filename);

    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);

    in >> this->numCols;

    int y;
    in >> y;

    QVector<int> inputs(y);
    for (int i = 0; i < y; ++i) {
        in >> inputs[i];
    }
    //this->inputs = inputs;

    QVector<int> goals(y);
    for (int i = 0; i < y; ++i) {
        in >> goals[i];
    }
    //this->goals = goals;
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

QVector<int> Level::getGoals()
{
    return goals;
}

QVector<GatePipeTags> Level::getLayout()
{
    return layout;
}

int Level::getNumColumns()
{
    return numCols;
}

int Level::getNumRows()
{
    return goals.size();
}

void Level::addGateWithStartGateInput(int gIndex, int sgIndex, int sgValue)
{

}

void Level::addGateWithGateInput(int gIndex, int igIndex)
{

}

void Level::addEndGateWithGateInput(int egIndex, int gIndex)
{

}
