#include "Stack.h"
# include <iostream>

using namespace std;

Stack::Stack()
{
	Top == nullptr;

}

Stack::~Stack()
{
}

void Stack::Push(int data)
{
	CNode *Pushed = Top;
	CNode *NewTop = new CNode;

	//connect the new top
	NewTop->SetNextNode(Pushed);
	NewTop->SetPrevNode(nullptr);
	NewTop->SetData(data);
	Top = NewTop;
	if (Pushed != nullptr) {
		Pushed->SetPrevNode(Top);
	}
	return;
}

void Stack::Pop(int & dataref)
{
	if (!IsEmpty()){
		CNode *Popped = Top;
		//if Top is the last node
		if (Popped->GetNextNode() == nullptr) {
			dataref = Top->GetData();
			Top->SetData(0);
			Top = nullptr;
			return;
		}

		
		CNode *NewTop = Popped->GetNextNode();

		//disconnect the popped node
		NewTop->SetPrevNode(nullptr);
		Popped->SetNextNode(nullptr);
		//return the value of popped
		dataref = Popped->GetData();
		//delete popped
		delete Popped;

		Top = NewTop;
		return;
	}
	return;
}

bool Stack::Peek(int & dataref)
{
	if (!IsEmpty()) {
		dataref = Top->GetData();
		return true;
	}
	else return false;
}

bool Stack::IsEmpty()
{
	if (Top == nullptr) {
		return true;
	}
	else return false;
	
}

