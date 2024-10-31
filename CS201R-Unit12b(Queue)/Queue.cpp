#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
}

Queue::~Queue() {
	Node* tempPtr = front;
	Node* holdPtr = tempPtr;
	while (tempPtr != nullptr) {
		tempPtr = tempPtr->nextPtr;
		delete holdPtr;
		holdPtr = tempPtr;
	}
}

bool Queue::isEmpty() {
	// check for empty list
	if (front == nullptr)
		return true;
	return false;
}

void Queue::enQueue(Data d) {
	// create node
	Node* newNode = new Node;
	newNode->data = d;
	newNode->nextPtr = nullptr;

	//add to empty list?
	if (front == nullptr) {
		front = newNode;
		rear = newNode;
	}
	//add to end of list
	else {
		rear->nextPtr = newNode;
		rear = newNode;
	}
}

Data Queue::deQueue() {
	// check for empty list
	if (front != nullptr) {
		Node* tempPtr = front;
		Data tempData = tempPtr->data;
		front = front->nextPtr;
		delete tempPtr;
		tempPtr = nullptr;
		return tempData;
	}
}

Data Queue::peek() {
	// check for empty list
	if (front != nullptr)
		return front->data;
}

void Queue::printQueue() {
	Node* tempPtr = front;
	while (tempPtr != nullptr) {
		cout << tempPtr->data.groupID << endl;
		tempPtr = tempPtr->nextPtr;
	}
}
