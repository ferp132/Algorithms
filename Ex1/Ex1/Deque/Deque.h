#include "CNode.h"

class Deque {

private:
	CNode *Front;
	CNode *Back;

public:

	Deque();
	~Deque();

	void Enqueue_Front(int data);
	void Enqueue_Back(int data);
	bool Dequeue_Front(int& dataref);
	bool Dequeue_Back(int& dataref);
	bool Peek_Front(int& dataref);
	bool Peek_Back(int& dataref);
	bool IsEmpty();
};
