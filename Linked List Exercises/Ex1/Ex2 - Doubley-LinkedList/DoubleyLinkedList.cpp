#include "DoubleyLinkedList.h"
#include <iostream>
using namespace std;

DoubleyLinkedList::DoubleyLinkedList()								//Constructor
{
	//root->SetPrevNode(nullptr);										//Set the Previous Node for the root to a nullptr so its not pointing somewhere strange
}

DoubleyLinkedList::~DoubleyLinkedList()								//Destructor
{

}

void DoubleyLinkedList::InsertAtTheFront(int value)					//Create A new CNode and insert it at the front of the list
{
	CNode * temp = root;											//Create a tempoary node to safely store the value in root
	CNode * newNode = new CNode();									//Create a New Node to become our new root
	newNode->SetData(value);										//Set that new node's data value equal to our input
	newNode->SetNextNode(root);										//Set the new node's next node equal to the original root
	newNode->SetPrevNode(nullptr);									//Set the new Node's prev node equal to the original root, which should be nullptr
	root = newNode;					
}

void DoubleyLinkedList::InsertInTheMiddle(int value, int position)	//Create a new CNode at the designated position of the list
{
	CNode * Current = root;											//Create a tempoary pointer to the current node we are looking at
	CNode * Latter = nullptr;										//The second node after the position that our new node will be inserted
	CNode * NewNode = new CNode();									//The New Node to be inserted
	NewNode->SetData(value);										//Assign the value
	
	if (position == 0)												//if the position is 0, it is the same as the InsertAtTheFront function so that will be run
	{
		InsertAtTheFront(value);
		return;
	}

	for (int i = 1; i < position; i++) {							//Execute this loop 'position' times, starts from 1, because otherwise you would just use the insert at beginning function.
		Current = Current->GetNextNode();							//Go to the next node in the list.
	}

	if (Current->GetNextNode() == nullptr)
	{
		InsertAtTheEnd(value);
		return;
	}

	Current->SetNextNode(NewNode);									
	Latter = Current->GetNextNode();
	Latter->SetPrevNode(NewNode);	
	NewNode->SetPrevNode(Current);															
	NewNode->SetNextNode(Latter);									
}

void DoubleyLinkedList::InsertAtTheEnd(int value)					//Insert a new CNode at the end of the list
{
	CNode * Current = root;											//Create a tempoary pointer to the current node we are looking at
	CNode * NewNode = new CNode();									//The New Node to be inserted
	NewNode->SetData(value);										//Assign the value

	while(Current->GetNextNode() != nullptr) {						//Execute this loop if the next root isnt null (0) i.e the end node
		Current = Current->GetNextNode();							//Go to the next node in the list.
	}
	Current->SetNextNode(NewNode);									//Make the last node in the list point to our NewNode
	NewNode->SetNextNode(nullptr);									//Set the next node to a null pointer
	NewNode->SetPrevNode(Current);
}

void DoubleyLinkedList::Delete(int value)							//Find a node in the linked list that is equal to this value, delete it and connect the nodes on either side
{

	if (Search(value))
	{
		CNode * Current = root;
		CNode * ToDelete = nullptr;
		CNode * ToConnect = nullptr;

		if (Current->GetData() == value)
		{
			ToDelete = Current;
			ToConnect = ToDelete->GetNextNode();

			ToConnect->SetPrevNode(nullptr);
			delete ToDelete;
			root = ToConnect;
			return;
		}

		while (Current->GetNextNode() != nullptr) {

			if (Current->GetNextNode()->GetData() == value) {
				ToDelete = Current->GetNextNode();

				if (Current->GetNextNode()->GetNextNode() == nullptr)
				{
					Current->SetNextNode(nullptr);
				}else {
				ToConnect = Current->GetNextNode()->GetNextNode();
				Current->SetNextNode(ToConnect);
				ToConnect->SetPrevNode(Current);
			}
				delete ToDelete;
				return;
			}
			Current = Current->GetNextNode();
		}

	}
}

bool DoubleyLinkedList::Search(int value)
{
	CNode * Current = root;																	

	while (Current->GetData() != value) {		
		if (Current == nullptr)
		{
			return false;
		}
		Current = Current->GetNextNode();		
		
	}
	return true;
}

void DoubleyLinkedList::display()
{
	CNode * Current = root;		
							
	cout << "Root:" << endl;
	while (Current != nullptr) {	
		//Print out the prev node, also check if it is null
		cout << "Previous: ";
		if (Current->GetPrevNode() != nullptr) {

			cout << Current->GetPrevNode() << endl;
		}
		else cout << "NULL" << endl;
		//Print out the current address
		cout << "Address: " << Current << endl;
		//Print out the value of the current node
		cout << "Value: " << Current->GetData() << endl;
		//Print out the next node, also check if it is null
		cout << "Next: ";
		if (Current->GetNextNode() != nullptr) {

			cout << Current->GetNextNode() << endl;
		}
		else cout << "NULL" << endl;
		
		cout << "-------------------------" << endl;
		Current = Current->GetNextNode();		
	}

}
