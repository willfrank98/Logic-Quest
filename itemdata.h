/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * itemdata.h
 */

#ifndef ITEMDATA_H
#define ITEMDATA_H

#endif // ITEMDATA_H
enum ItemKey { Type, Name, Bounds, Draggable, Direction, StartPosition, Sheet, FrameSize, Frame };
enum PhysicsBodyType { Static, Dynamic, Kinematic };
enum GateNodeType {START, END, UNSET, AND, OR, NAND, NOR, XOR, NOT};
enum GatePipeTags {
    WN, // Bend from West to North
    EN, // Bend from East to North
    WS, // Bend from West to South
    ES, // Bend from East to South
    WE, // Horizontal
    NS, // Vertical
    S0, // Start gate for 0 input
    S1, // Start gate for 1 input
    EG, // End gate
    UG, // Unset gate
    AG, // And gate
    OG, // Or gate
    NL  // Empty/null space
};
