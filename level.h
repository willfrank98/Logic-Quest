/*
 * Death Star IT Support
 * CS3505 - A8: An Agile Educational Application
 *
 * level.h
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <gatenode.h>
#include <QFile>
#include <QDebug>
#include <regex>

class Level
{
private:
    QVector<GateNode*> startGates;
    QVector<GateNode*> endGates;
    QVector<GateNode*> gates;
    QVector<int> goals;
    QVector<int> endGateLocations;
    QVector<GatePipeTags> layout;
    QVector<int> gateNodeIndex;
    int numCols;
    int numRows;
    int difficulty;
    bool levelIsTut;
    bool isComplete;
    bool perfLevel;
    int levelScore;
    void addGateWithStartGateInput(int gIndex, int sgIndex, int sgValue);
    void addGateWithGateInput(int gIndex, int igIndex);
    void addEndGateWithGateInput(int egIndex, int gIndex);
    GateNodeType getGateTypeEnum(QString str);
    GatePipeTags getLayOutEnum(QString str);
	QString nextLevelAddress;
    QString levelNumber;
    QString difficultyString;

public:
    Level();
    Level(QString filename);
	bool checkOutputs();
    QVector<int> setGateType(int gateIndex, GateNodeType type);
    QVector<int> getGoals();
    QVector<GatePipeTags> getLayout();
    QVector<GateNode*> getEndGates();
    int getNumColumns();
    int getNumRows();
    int getGateNodeIndex(int layoutIndex);
    int getScore();
    bool hasTwoInputs(int index);
    bool completedPerfectLevel();
	QString nextLevel();
    QString getLevelNumber();
    void setLevelNumber(QString name);
    QString getDifficultyString();
    void setDifficultyString(QString diff);
    bool isTutorial();
};

#endif // LEVEL_H
