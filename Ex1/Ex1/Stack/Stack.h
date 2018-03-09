#include "CNode.h"

class Stack {

private:
	CNode *Top;

public:
	Stack();
	~Stack();

	void Push(int data);
	void Pop(int& dataref);
	bool Peek(int& dataref);
	bool IsEmpty();
};
