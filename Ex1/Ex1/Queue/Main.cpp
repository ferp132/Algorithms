#include "Queue.h"
#include "CNode.h"
#include <iostream>

using namespace std;

int main() {
	
	Queue myqueue;
	int x;

	myqueue.Enqueue(10);
	myqueue.Enqueue(5);
	myqueue.Enqueue(1);
	myqueue.Enqueue(2);
	myqueue.Enqueue(3);
	myqueue.Enqueue(4);

	
	
	myqueue.Dequeue(x);
	cout << "dequeued: " << x << endl;
	myqueue.Dequeue(x);
	cout << "dequeued: " << x << endl;
	myqueue.Dequeue(x);
	cout << "dequeued: " << x << endl;
	myqueue.Dequeue(x);
	cout << "dequeued: " << x << endl;
	myqueue.Dequeue(x);
	cout << "dequeued: " << x << endl;
	myqueue.Dequeue(x);
	cout << "dequeued: " << x << endl;

	int i;
	cin >> i;

	return 0;
}