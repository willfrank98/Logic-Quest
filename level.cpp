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
    startGates = newInputs;
    endGates = newOutputs;
    gates = newGates;
    goals = newGoals;
    numCols = newRowSize;
    layout = newLayout;
}

Level::Level(QString filename)
{
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly))
    {

        QTextStream indata(&file);
        QString line;
        int currentLine = 0;
        while (!indata.atEnd())
        {
            line = indata.readLine().simplified();

            if(currentLine == 0)
            {

            }
        }
    }
    file.close();
}

void Level::checkOutputs()
{
    for (int i = 0; i < goals.size(); i++)
    {
        if(goals[i] != endGates[i].getOutput())
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
    bool isNewGate = false;
    if(gates.size() = gIndex)
    {
        gates.append(new GateNode(UNSET, -1));
        isNewGate = true;
    }
    if(startGates.size() = sgIndex)
    {
        startGates.append(new GateNode(START, sgValue));
    }

    //If the gate at gIndex is new, add startGate at sgIndex as input 1
    if(isNewGate)
    {
        gates[gIndex].addInput(1, startGates[sgInde]);
    }
    //Otherwise add startGate at sgIndex as input 2
    else
    {
        gates[gIndex].addInput(2, startGates[sgInde]);
    }
}

void Level::addGateWithGateInput(int gIndex, int igIndex)
{
    bool isNewGate = false;

    //If the a gate with index gIndex does not already exist in gates,
    //A new gate is created and added
    if(gates.size() = gIndex)
    {
        gates.append(new GateNode(UNSET, -1));
        isNewGate = true;
    }

    //It is assumed that a gate already exists in gates at index igIndex.

    //If the gate at gIndex is new, add gate at igIndex as input 1
    if(isNewGate)
    {
        gates[gIndex].addInput(1, gates[igIndex]);
    }
    //Otherwise add gate at igIndex as input 2
    else
    {
        gates[gIndex].addInput(2, gates[igIndex]);
    }
}

void Level::addEndGateWithGateInput(int egIndex, int gIndex)
{
    //It is assumed that a gate already exists in gates at index gIndex.

    //Since an endGate can only have 1 input, it is assumed that the endGate
    //does not already exist and needs to be created and added to endGates.
    endGates.append(new GateNode(END, -1));

    endGates[egIndex].addInput(1, gates[gIndex]);

}

GatePipeTags Level::getLayOutEnum(QString str)
{
    if(str.startsWith('W'))
    {
        if(str == "WE")
        {
            return WE;
        }
        if(str == "WN")
        {
            return WN;
        }
        if(str == "WS")
        {
            return WS;
        }
    }
    if(str.startsWith('E'))
    {
        if(str == "EG")
        {
            return EG;
        }
        if(str == "EN")
        {
            return EN;
        }
        if(str == "ES")
        {
            return ES;
        }
    }
    if(str == "NL")
    {
        return NL;
    }
    if(str == "UG")
    {
        return UG;
    }
    if(str == "S1")
    {
        return S1;
    }
    if(str == "S0")
    {
        return S0;
    }
    if(str == "NS")
    {
        return NS;
    }
    return NL;
}
