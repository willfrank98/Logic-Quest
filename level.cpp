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

    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);
    QString nextLine = in.readLine();
    QStringList ls = nextLine.split(' '); ///////"this"????
    this->numRows = ls[0].toInt();
    this->numCols = ls[1].toInt();
    qDebug() << "numRows: "<< numRows << "numCols: " << numCols;

    //QVector<QString> gridStrings;
    QVector<GateNode> *nodeVec = new QVector<GateNode>();
    QVector<GatePipeTags> *pipeTags = new QVector<GatePipeTags>();
    for (int i = 0; i < numRows; ++i) {
        nextLine = in.readLine();
        ls = nextLine.split(" ");
        qDebug() << nextLine;
        for (int i = 0; i < numCols; ++i) {
            GateNode current;
            if (getEnumType(ls[i])== "pipe"){
                pipeTags->push_back(WN); // change this to helper which gets right pipe tag
                continue;
                //current.setGateType(NULL);
                // push to layout....the GatePipeTagsHolder
            }
            else if (getEnumType(ls[i]) == "start"){
                current.setGateType(START);
            }
            else if (getEnumType(ls[i]) == "end"){
                current.setGateType(END);
            }
            else if (getEnumType(ls[i]) == "unsetgate"){
                current.setGateType(UNSET);
            }
            else{
              //empty space
            }
            //qDebug() << (QString) current.gType;
            nodeVec->push_back(current);
        }
    }
    QString goall = in.readLine();
    qDebug() << goall;

    // below is where things get shakey
    QVector<GateNode> inputsV(2);// how do we know the number of inputs again?
    QVector<GateNode> outputsV(1); // how do we know this?
    QVector<GateNode> gatesV(1); // i probably understand this one the least
    QVector<int> goals(1);
    // this should be done in the 3 iteration loop i think
    goals.append(0);
    inputsV.append(GateNode());
    inputsV.append(GateNode());
    outputsV.append(GateNode());
    gatesV.append(GateNode());
    this->isComplete = false;
    this->gates = gatesV;
    this->inputs = inputsV;
    this->outputs = outputsV;
    this->goals = goals;
    this->layout = *pipeTags;

    // grab startgate, endgate, and gate info
    // I do not understand this seconds matrix
//    for (int i = 1; i <= 3; ++i) { // questionable
//        if (i < 3){
//            nextLine = in.readLine();
//            ls = nextLine.split(" ");
//            qDebug() << nextLine;
//            inputsV[ls[1].toInt()] = ls[2].toInt(); // first two rows of last matrix
//            gatesV[0] = gatesV[ls[(4)]];
//        }
//        else{
//            nextLine = in.readLine();
//            ls = nextLine.split(" ");
//            //outputs[ls[3]]
//            //gatesV[ls[1]] = ls[2]];
//        }
//    }
}
QString Level::getEnumType(QString str){
    QString tag = str;
    if (tag == "WN" ||tag == "EN" ||tag == "WS" ||tag == "ES"
            ||tag == "WE" ||tag == "NE")
        return "pipe";
    if (tag == "S0" || tag == "S1")
        return "startgate";
    if (tag == "EG")
        return "endgate";
    if (tag == "UG")
        return "unsetgate";
    return "emptyspace";
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
    return numRows;
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
