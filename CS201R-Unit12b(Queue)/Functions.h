#pragma once
#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;


//data structure to store info about a train
struct trainInfo {
    int trainID = 0;
    vector<int> groupId;
    int trainCount = 0;
};

void loadData(Queue& theLine, int& trainSize);
//PRE: theLine must be a valid Queue object, trainSize must be a valid int
//POST: theLine will be loaded with data from the file, trainsize will be updated

void processTheLine(Queue& theLine, vector<trainInfo>& theTrain, int trainSize);
//PRE: theLine must be a valid Queue object, theTrain must be a valid vector of trainInfo objects, trainSize must be a valid int
//POST: theTrain will contain info about formed trained

void printTheTrain(vector<trainInfo> theTrain);
//PRE: theTrain will be a valid object containing train info
//POST: info about all trains will be printed

