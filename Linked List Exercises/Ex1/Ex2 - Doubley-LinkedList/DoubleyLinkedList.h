#ifndef _LINKEDLIST_H__
#define _LINKEDLIST_H__

#include "CNode.h"

class DoubleyLinkedList {

private:
	CNode *root;

public:
	DoubleyLinkedList();
	~DoubleyLinkedList();

	void InsertAtTheFront(int value);

	void InsertInTheMiddle(int value, int position);

	void InsertAtTheEnd(int value);

	void Delete(int value);

	bool Search(int value);

	void display();
};

#endif