#include "Queue.h"

Queue::Queue()
{
	Front = nullptr;
	Back = nullptr;

}

Queue::~Queue()
{
}

void Queue::Enqueue(int data)
{
	CNode *NewNode = new CNode;
	CNode *NextInLine = nullptr;

	if (Front == nullptr) {
		Front = NewNode;
		Front->SetData(data);
	}
	else if (Back == nullptr) {
		Back = NewNode;
		Back->SetData(data);
		Back->SetPrevNode(Front);
		Front->SetNextNode(Back);
	}
	else {
		NextInLine = Back;
		NewNode->SetPrevNode(NextInLine);
		NextInLine->SetNextNode(NewNode);
		Back = NewNode;
		Back->SetData(data);
	}
}

bool Queue::Dequeue(int & dataref)
{
	if (!IsEmpty()) {
		CNode *Dequeued = Front;

		if (Front->GetNextNode() == nullptr) Front = nullptr;
		else{
			Front->SetPrevNode(nullptr);
			Front = Dequeued->GetNextNode();
			}
		
		dataref = Dequeued->GetData();
		

		delete Dequeued;
		return true;
	}
	return false;
}

bool Queue::Peek(int & dataref)
{
	if (!IsEmpty()) {
		dataref = Front->GetData();
		return true;
	}
	return false;
}

bool Queue::IsEmpty()
{
	if (Front == nullptr) return true;
	else return false;
}
