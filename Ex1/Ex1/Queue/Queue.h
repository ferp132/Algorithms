#include "CNode.h"

class Queue {

private:
	CNode *Front;
	CNode *Back;

public:

	Queue();
	~Queue();

	void Enqueue(int data);
	bool Dequeue(int& dataref);
	bool Peek(int& dataref);
	bool IsEmpty();
};
