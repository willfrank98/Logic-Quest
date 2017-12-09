/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * level.cpp
 */

#include "level.h"
#include <QFile>
#include <QDebug>

Level::Level()
{
    isComplete = false;
    numCols = 0;
    numRows = 0;
}

Level::Level(QString filename)
{
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly))
    {

        QTextStream indata(&file);
        QString line;
        QStringList list;
        int currentLine = 0;
        while (!indata.atEnd())
        {
            line = indata.readLine().simplified();
            list = line.split(" ");

            //Parse the numRows and numCols
            if(currentLine == 0)
            {
                numRows = list[0].toInt();
                numCols = list[1].toInt();
                currentLine++;
                continue;
            }

            //Parse the layout
            if(currentLine > 0 && currentLine < numRows + 1)
            {
                for (QString s : list)
                {
                    layout.append(getLayOutEnum(s));
                }
                currentLine++;
                continue;
            }

            //Parse the goal values
            if(currentLine == numRows + 1)
            {

                for (QString s : list)
                {
                    goals.append(s.toInt());
                }
                currentLine++;
                continue;
            }

            //Parse the gate connections
            if(list[0] == "S")
            {
                int sgIndex = list[1].toInt();
                int sgValue = list[2].toInt();
                int gIndex = list[3].toInt();
                addGateWithStartGateInput(gIndex, sgIndex, sgValue);

            }
            else if(list[0] == "G")
            {
                int igIndex = list[1].toInt();
                int gIndex = list[2].toInt();
                addGateWithGateInput(gIndex, igIndex);
            }
            else if(list[0] == "E")
            {
                int egIndex = list[2].toInt();
                int gIndex = list[1].toInt();
                addEndGateWithGateInput(egIndex, gIndex);
            }

        }
    }
    file.close();
}

void Level::checkOutputs()
{
    for (int i = 0; i < goals.size(); i++)
    {
        if(goals[i] != endGates[i]->getOutput())
        {
            isComplete = false;
            return;
        }
    }
    isComplete = true;
}

void Level::setGateType(int gateIndex, GateNodeType type)
{
    gates[gateIndex]->setGateType(type);
    gates[gateIndex]->processGate();
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
    return numRows;
}

void Level::addGateWithStartGateInput(int gIndex, int sgIndex, int sgValue)
{
    bool isNewGate = false;
    GateNode *gate, *startGate;
    if(gates.size() == gIndex)
    {
        gate = new GateNode(UNSET, -1);
        gates.append(gate);
        isNewGate = true;
    }
    if(startGates.size() == sgIndex)
    {
        startGate = new GateNode(START, sgValue);
        startGates.append(startGate);
    }

    //If the gate at gIndex is new, add startGate at sgIndex as input 1
    if(isNewGate)
    {
        gates[gIndex]->addInput(1, startGates[sgIndex]);
    }
    //Otherwise add startGate at sgIndex as input 2
    else
    {
        gates[gIndex]->addInput(2, startGates[sgIndex]);
    }
}

void Level::addGateWithGateInput(int gIndex, int igIndex)
{
    bool isNewGate = false;
    GateNode *gate;

    //If the a gate with index gIndex does not already exist in gates,
    //A new gate is created and added
    if(gates.size() == gIndex)
    {
        gate = new GateNode(UNSET, -1);
        gates.append(gate);
        isNewGate = true;
    }

    //It is assumed that a gate already exists in gates at index igIndex.

    //If the gate at gIndex is new, add gate at igIndex as input 1
    if(isNewGate)
    {
        gates[gIndex]->addInput(1, gates[igIndex]);
    }
    //Otherwise add gate at igIndex as input 2
    else
    {
        gates[gIndex]->addInput(2, gates[igIndex]);
    }
}

void Level::addEndGateWithGateInput(int egIndex, int gIndex)
{
    //It is assumed that a gate already exists in gates at index gIndex.

    //Since an endGate can only have 1 input, it is assumed that the endGate
    //does not already exist and needs to be created and added to endGates.
    GateNode *endGate = new GateNode(END, -1);
    endGates.append(endGate);

    endGates[egIndex]->addInput(1, gates[gIndex]);

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
