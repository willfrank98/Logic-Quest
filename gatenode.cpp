/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * gatenode.cpp
 */

#include "gatenode.h"

GateNode::GateNode(GateNode* inputNode1, GateNode* inputNode2, GateNodeType type, int value)
{
    input1 = inputNode1;
    input2 = inputNode2;
    gType = type;
    if(gType == START) {
            output = value;
    }
}

GateNode::~GateNode()
{

}

int GateNode::getOutput()
{
    return output;
}

int GateNode::andGate()
{
    //Adds the output for the two inputs
    int output = input1->getOutput() + input2->getOutput();

    //If both inputs are 1 then return 1, otherwise returns 0
    if(output == 2) {
        return 1;
    }
    else return 0;
}

int GateNode::nandGate()
{
    //Adds the output for the two inputs
    int output = input1->getOutput() + input2->getOutput();

    //If both inpts are 1 return 0, otherwise returns 1
    if(output == 2) {
        return 0;
    }
    else return 1;
}

int GateNode::norGate()
{
    //Adds the output for the two inputs
    int output = input1->getOutput() + input2->getOutput();

    //If both inputs are 0 return 1, otherwise returns 0
    if(output == 0) {
        return 1;
    }
    else return 0;
}

int GateNode::notGate()
{
    //Grabs the output from the input.
    int output = input1->getOutput();

    //If input is 0 return 1, if input is 1 return 0
    if(output == 0) {
        return 1;
    }
    else return 0;
}

int GateNode::orGate()
{
    //Adds the output for the two inputs
    int output = input1->getOutput()+ input2->getOutput();

    //If both inputs are 0 return 0, otherwise return 1
    if(output == 0) {
        return 0;
    }
    else return 1;
}

int GateNode::xorGate()
{
    //Adds the output for the two inputs
    int output = input1->getOutput() + input2->getOutput();

    //If one input is 1 and the other input is 0 return 1, otherwise return 0
    if(output == 1) {
        return 1;
    }
    else return 0;
}

void GateNode::processGate()
{
    switch(gType)
    {
       case AND:
        output = andGate();
        break;
       case NAND:
        output = nandGate();
        break;
    case NOR:
        output = norGate();
        break;
    case NOT:
        output = notGate();
        break;
    case OR:
        output = orGate();
        break;
    case XOR:
        output = xorGate();
        break;
    case END:
        output = input1->getOutput();
        break;
    default:
        break;
    }
}

void GateNode::setGateType(GateNodeType type)
{
    //if the specified type is NOT, makes sure there is only one input
    if(type == NOT)
    {
        //checks if there are two inputs and the specified type is NOT, the GateNodeType is not changed.
        if(input2 != nullptr)
        {
            return;
        }
    }
    gType = type;
}