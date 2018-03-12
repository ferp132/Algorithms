#include "Deque.h"

Deque::Deque()
{
	Front = nullptr;
	Back = nullptr;

}

Deque::~Deque()
{
}

void Deque::Enqueue_Back(int data)
{
	CNode *NewNode = new CNode;
	CNode *NextInLine = nullptr;

	if (Back == nullptr) {
		Back = NewNode;
		Back->SetData(data);
	}
	else if (Front == nullptr) {
		Front = NewNode;
		Front->SetData(data);
		Front->SetNextNode(Front);
		Front->SetPrevNode(Back);
	}
	else {
		NextInLine = Front;
		NewNode->SetNextNode(NextInLine);
		NextInLine->SetPrevNode(NewNode);
		Front = NewNode;
		Front->SetData(data);
	}
}

bool Deque::Dequeue_Back(int & dataref)
{
	if (!IsEmpty()) {
		CNode *Dequeued = Back;

		if (Back->GetPrevNode() == nullptr) Back = nullptr;
		else {
			Back->SetNextNode(nullptr);
			Back = Dequeued->GetPrevNode();
		}

		dataref = Dequeued->GetData();


		delete Dequeued;
		return true;
	}
	return false;
}

void Deque::Enqueue_Front(int data)
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

bool Deque::Dequeue_Front(int & dataref)
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

bool Deque::Peek_Front(int & dataref)
{
	if (!IsEmpty()) {
		dataref = Front->GetData();
		return true;
	}
	return false;
}

bool Deque::Peek_Back(int & dataref)
{
	if (!IsEmpty()) {
		dataref = Back->GetData();
		return true;
	}
	return false;
}

bool Deque::IsEmpty()
{
	if (Front == nullptr && Back == nullptr) return true;
	else return false;
}
