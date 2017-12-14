/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * gatenode.h
 */

#ifndef GATENODE_H
#define GATENODE_H

#include <itemdata.h>
#include <QVector>

class GateNode
{
private:
    GateNode* inputNode1;
    GateNode* inputNode2;
    GateNode* outputNode;
    int output;
    int endGateLocation; //is the location in the layout of the endGate associated with this node
    GateNodeType gType;

    //helper methods for processGate()
    int andGate(); //Takes the output from the two inputs and calculates the AND boolean value
    int nandGate(); //Takes the output from the two inputs and calculates the NAND boolean value
    int norGate(); //Takes the output from the two inputs and calculates the NOR boolean value
    int notGate(); //Takes the output from the two inputs and calculates the NOT boolean value
    int orGate(); //Takes the output from the two inputs and calculates the OR boolean value
    int xorGate(); //Takes the output from the two inputs and calculates the XOR boolean value

public:
    GateNode();
    GateNode(GateNodeType type, int value);
    ~GateNode();
    int getOutput();    //returns the output of this node
    int getEndGateLocation();
    QVector<int> processGate(); //processes the input to set the output based on the type of the GateNode
    void setGateType(GateNodeType type); //sets the GateNodeType to the specified type
    void addInput(int inputNum, GateNode *node);
    void setEndGateLocation(int location);
    bool hasTwoInputs();
    bool hasOneInput();
};

#endif // GATENODE_H
