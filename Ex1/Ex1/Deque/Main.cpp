#include "Deque.h"
#include "CNode.h"
#include <iostream>

using namespace std;

int main() {
	
	Deque mydeque;
	int x;

	mydeque.Enqueue_Front(10);
	mydeque.Enqueue_Front(5);
	mydeque.Enqueue_Back(1);
	mydeque.Enqueue_Back(2);
	mydeque.Enqueue_Front(3);
	mydeque.Enqueue_Back(4);

	
	
	mydeque.Dequeue_Front(x);
	cout << "dequeued: " << x << endl;
	mydeque.Dequeue_Front(x);
	cout << "dequeued: " << x << endl;
	mydeque.Dequeue_Front(x);
	cout << "dequeued: " << x << endl;
	mydeque.Dequeue_Back(x);
	cout << "dequeued: " << x << endl;
	mydeque.Dequeue_Back(x);
	cout << "dequeued: " << x << endl;
	mydeque.Dequeue_Back(x);
	cout << "dequeued: " << x << endl;

	int i;
	cin >> i;

	return 0;
}