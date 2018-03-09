#include <iostream>
#include "CNode.h"
#include "SingleLinkedList.h"

using namespace std;

int main() {

	SingleLinkedList List;

	List.InsertAtTheFront(5);
	List.InsertAtTheEnd(10);
	List.InsertInTheMiddle(15, 2);

	List.display();

	cout << endl << endl;

	List.Delete(10);
	List.display();


	cout << endl << endl;

	List.InsertAtTheEnd(20);
	List.InsertAtTheEnd(25);
	List.display();

	cout << endl << endl;

	List.Delete(25);
	List.display();

	int i;
	cin >> i;

	return 0;

}