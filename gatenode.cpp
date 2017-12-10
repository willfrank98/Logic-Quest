/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * gatenode.cpp
 */

#include "gatenode.h"

GateNode::GateNode()
{

}

GateNode::GateNode(GateNodeType type, int value)
{
    gType = type;
    inputNode1 = nullptr;
    inputNode2 = nullptr;
    outputNode = nullptr;
    output = -1;
    endGateLocation = -1;
    if(gType == START)
    {
        output = value;
        if(output > 1)
        {
            output = 1;
        }
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
    //checks if output from input nodes are set
    if(inputNode1->getOutput() < 0 || inputNode2->getOutput() < 0) {
        return -1;
    }

    //Adds the output for the two inputs
    int output = inputNode1->getOutput() + inputNode2->getOutput();

    //If both inputs are 1 then return 1, otherwise returns 0
    if(output == 2) {
        return 1;
    }
    else return 0;
}

int GateNode::nandGate()
{
    //checks if output from input nodes are set
    if(inputNode1->getOutput() < 0 || inputNode2->getOutput() < 0) {
        return -1;
    }

    //Adds the output for the two inputs
    int output = inputNode1->getOutput() + inputNode2->getOutput();

    //If both inpts are 1 return 0, otherwise returns 1
    if(output == 2) {
        return 0;
    }
    else return 1;
}

int GateNode::norGate()
{
    //checks if output from input nodes are set
    if(inputNode1->getOutput() < 0 || inputNode2->getOutput() < 0) {
        return -1;
    }

    //Adds the output for the two inputs
    int output = inputNode1->getOutput() + inputNode2->getOutput();

    //If both inputs are 0 return 1, otherwise returns 0
    if(output == 0) {
        return 1;
    }
    else return 0;
}

int GateNode::notGate()
{
    //checks if output from input nodes are set
    if(inputNode1->getOutput() < 0 || inputNode2->getOutput() < 0) {
        return -1;
    }

    //Grabs the output from the input.
    int output = inputNode1->getOutput();

    //If input is 0 return 1, if input is 1 return 0
    if(output == 0) {
        return 1;
    }
    else return 0;
}

int GateNode::orGate()
{
    //checks if output from input nodes are set
    if(inputNode1->getOutput() < 0 || inputNode2->getOutput() < 0) {
        return -1;
    }

    //Adds the output for the two inputs
    int output = inputNode1->getOutput()+ inputNode2->getOutput();

    //If both inputs are 0 return 0, otherwise return 1
    if(output == 0) {
        return 0;
    }
    else return 1;
}

int GateNode::xorGate()
{
    //checks if output from input nodes are set
    if(inputNode1->getOutput() < 0 || inputNode2->getOutput() < 0) {
        return -1;
    }

    //Adds the output for the two inputs
    int output = inputNode1->getOutput() + inputNode2->getOutput();

    //If one input is 1 and the other input is 0 return 1, otherwise return 0
    if(output == 1) {
        return 1;
    }
    else return 0;
}

QVector<int> GateNode::processGate()
{
    QVector<int> endResults;
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
        output = inputNode1->getOutput();
        endResults.append(endGateLocation);
        endResults.append(output);
        return endResults;
    default:
        return endResults;
    }
    if(output > -1)
    {
        endResults = outputNode->processGate();
    }
    return endResults;
}

void GateNode::setGateType(GateNodeType type)
{
    //if the specified type is NOT, makes sure there is only one input
    if(type == NOT)
    {
        //checks if there are two inputs and the specified type is NOT, the GateNodeType is not changed.
        if(inputNode2 != nullptr)
        {
            return;
        }
    }
    gType = type;
}

void GateNode::addInput(int inputNum, GateNode *node)
{
    if(gType != START)
    {
        if(inputNum == 1)
        {
            inputNode1 = node;
            node->outputNode = this;
            return;
        }
        if(inputNum = 2 && gType != NOT && gType != END)
        {
            inputNode2 = node;
            node->outputNode = this;
            return;
        }
    }
}

int GateNode::getEndGateLocation()
{
    return endGateLocation;
}

void GateNode::setEndGateLocation(int location)
{
    if(endGateLocation < 0)
    {
        endGateLocation = location;
    }
}

bool GateNode::hasTwoInputs()
{
    return inputNode2 != nullptr;
}
