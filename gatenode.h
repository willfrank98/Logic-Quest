/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * gatenode.h
 */

#ifndef GATENODE_H
#define GATENODE_H

#include <itemdata.h>

class GateNode
{
private:
    GateNode* inputNode1;
    GateNode* inputNode2;
    GateNode* outputNode;
    int output;
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
    GateNode(GateNode* _inputNode1, GateNode* _inputNode2, GateNode* _outputNode, GateNodeType type, int value);
    ~GateNode();
    int getOutput();    //returns the output of this node
    void processGate(); //processes the input to set the output based on the type of the GateNode
    void setGateType(GateNodeType type); //sets the GateNodeType to the specified type
};

#endif // GATENODE_H
