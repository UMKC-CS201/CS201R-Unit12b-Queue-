#pragma once

struct Data {
	int groupID;
	int groupCount;
};

struct Node {
	Data data;
	Node* nextPtr;
};

class Queue {
private:
	Node* front;
	Node* rear;
public:
	Queue();
	~Queue();
	void enQueue(Data d);
	Data deQueue();
	bool isEmpty();
	Data peek();
	void printQueue();

};
