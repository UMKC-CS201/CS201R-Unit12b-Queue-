#include "Functions.h"
#include "Queue.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//function to check if a string is only digits
bool isDigits(string str) {
    return (str.find_first_not_of("0123456789") == string::npos);
}

//function to load data from a file into a queue
void loadData(Queue& theLine, int& trainSize) {
    ifstream inFile;
    //open the file
    inFile.open("riders.txt");
    //check if the file is open
    if (!inFile.is_open()) {
        cout << "Error opening file\n";
        return;
    }

    //strings to store data from file
    string s1, s2;
    inFile >> s1;
    //check if the value is a digit
    if (isDigits(s1)) {
        trainSize = stoi(s1);
    }
    else {
        cout << "Invalid train size\n";
        return;
    }

    //read data pairs from the file and put them into the queue
    while (inFile >> s1 >> s2) {
        if (isDigits(s1) && isDigits(s2)) {
            //check if both are digits
            Data newData;
            //convert strings into integers
            newData.groupCount = stoi(s2);
            newData.groupID = stoi(s1);
            theLine.enQueue(newData);
        }
        else {
            //if invalid, continue
            continue;
        }
    }

    //close the file
    inFile.close();
}

//function to process the data in the queue and create the trains
void processTheLine(Queue& theLine, vector<trainInfo>& theTrain, int trainSize) {
    //variable to hold data from queue
    Data tempData;
    int trainID = 0;

    //process data until the queue is empty
    while (!theLine.isEmpty()) {
        //create a new train with new id and set groups to 0

        trainID++; 
        trainInfo tempTrain; //create a new train
        tempTrain.trainID = trainID; //set the train ID
        tempTrain.trainCount = 0; //set the train count to 0
        tempTrain.groupId.clear(); //clear the group ID vector

        //loop until the train is full or the queue is empty
        //peek at the front of the queue
        //if the next group can fit on the train, 
        //   dequeue the data, update the train
        //   and add the group to the current train train
        //otherwise, break out of this loop (the train is full or line is empty)
        while (tempTrain.trainCount < trainSize && !theLine.isEmpty()) {
            tempData = theLine.peek();
            if (tempTrain.trainCount + tempData.groupCount <= trainSize) {
                tempData = theLine.deQueue();
                tempTrain.trainCount += tempData.groupCount;
                tempTrain.groupId.push_back(tempData.groupID);
            }
            else {
                break;
            }
        }
        //add the train to the vector
        theTrain.push_back(tempTrain);
    }
}

//function to print the trains
//loop through all trains and print their info
void printTheTrain(vector<trainInfo> theTrain) {
    cout << "-----------------------------------------------------------" << endl;
    cout << setw(15) << "TRAIN ID" << setw(15) << "TRAIN CT" << setw(15) << "GROUP LIST" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < theTrain.size(); i++) {
        cout << setw(15) << theTrain[i].trainID << setw(15) << theTrain[i].trainCount;
        for (unsigned int j = 0; j < theTrain.at(i).groupId.size(); j++) {
            cout << setw(4) << theTrain.at(i).groupId.at(j);
        }
        cout << endl;
    }
 
    cout << "Total trains: " << theTrain.size() << endl << endl;
}