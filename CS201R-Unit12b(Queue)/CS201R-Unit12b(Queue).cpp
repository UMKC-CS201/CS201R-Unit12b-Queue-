// CS201R-Unit12b(Queue).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Functions.h"
#include "Queue.h"
using namespace std;

int main() {
    //create a queue
    Queue theLine;

    //create a vector to hold the trains
    vector<trainInfo> theTrain;

    //variable to hold the train size
    int trainSize;

    loadData(theLine, trainSize);                   //load data from the file
    //theLine.printQueue();

    processTheLine(theLine, theTrain, trainSize);   //process the data in the queue and create the trains
    printTheTrain(theTrain);                        //print the trains
}
