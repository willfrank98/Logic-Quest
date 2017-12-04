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
    int output = input1->getOutput() + input2->getOutput();
    if(output == 2) {
        return 1;
    }
    else return 0;
}

int GateNode::nandGate()
{
    int output = input1->getOutput() + input2->getOutput();
    if(output == 2) {
        return 0;
    }
    else return 1;
}

int GateNode::norGate()
{
    int output = input1->getOutput() + input2->getOutput();
    if(output == 0) {
        return 1;
    }
    else return 0;
}

int GateNode::notGate()
{
    int output = input1->getOutput();
    if(output == 0) {
        return 1;
    }
    else return 0;
}

int GateNode::orGate()
{
    int output = input1->getOutput()+ input2->getOutput();
    if(output == 0) {
        return 0;
    }
    else return 1;
}

int GateNode::xorGate()
{
    int output = input1->getOutput() + input2->getOutput();
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
    gType = type;
}
