#include "Stack.h"
#include "CNode.h"
#include <iostream>

using namespace std;

int main() {
	Stack mystack;
	int x;

	mystack.Peek(x);
	cout << "Peeking: " << x << endl;
	mystack.Push(5);
	mystack.Push(10);
	mystack.Push(0);
	mystack.Push(-5);
	mystack.Peek(x);
	cout << "Peeking: " << x << endl;
	mystack.Push(15);
	mystack.Push(30);
	mystack.Push(20);

	for (int i = 0; i < 4; i++) {
		mystack.Pop(x);
		cout << "Popped: " << x << endl;
	}

	cout << "Pushing" << endl;

	mystack.Push(100);
	mystack.Push(45);

	while(!mystack.IsEmpty()) {
		mystack.Pop(x);
		cout << "Popped: " << x << endl;
	}

	mystack.Peek(x);
	cout << "Peeking: " << x << endl;

	int i;
	cin >> i;

	return 0;
}