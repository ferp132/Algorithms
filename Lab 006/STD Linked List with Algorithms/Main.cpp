#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void PrintInt(int i)
{
	cout << i << ", ";
}

bool IsOdd(int i) 
{
	return ((i % 2) == 1);
}

int main() 
{
	std::list<int> mylist;

	mylist.push_back(10);
	mylist.push_back(50);
	mylist.push_back(53);
	mylist.push_back(20);
	mylist.push_back(50);
	mylist.push_back(25);
	mylist.push_back(35);
	mylist.push_back(40);
	mylist.push_back(40);
	mylist.push_back(35);
	mylist.push_back(50);
	mylist.push_back(31);
	mylist.push_back(50);

	cout << "Container elements: ";

	//Test for_each:
	for_each(mylist.begin(), mylist.end(), PrintInt);

	cout << endl;

	//Test find, with element in container:
	std::list<int>::iterator iter = find(mylist.begin(), mylist.end(), 20);

	if (iter == mylist.end())
	{
		cout << "20, Not Found!" << endl;
	}
	else
	{
		cout << "Found: " << *iter << endl;
	}

	//Test find, with element not in container:
	iter = find(mylist.begin(), mylist.end(), 47);

	if (iter == mylist.end())
	{
		cout << "47, not found!" << endl;
	}
	else
	{
		cout << "Found: " << *iter << endl;
	}

	// Test count, how many times is 50 in the container?
	int iCount = static_cast<int>(count(mylist.begin(), mylist.end(), 50));

	cout << "50 is in the container " << iCount << " times!" << endl;

	// Test count_if, how many items are odd?
	iCount = static_cast<int>(count_if(mylist.begin(), mylist.end(), IsOdd));
	
	cout << iCount << " odd numbers in the container!" << endl;

	// Test remove, all the items of value 50.
	iter = remove(mylist.begin(), mylist.end(), 50);
	//Remove moces the items in the container to be removed to the enf, and then returns an iterator
	//for the first item to be removed. erase must then be called to remove the items!
	mylist.erase(iter, mylist.end());

	//Check the container:
	cout << "container elements: ";
	for_each(mylist.begin(), mylist.end(), PrintInt);
	cout << endl;

	//Test sort:
	mylist.sort();

	//Check the container:
	cout << "Sorted container elements: ";
	for_each(mylist.begin(), mylist.end(), PrintInt);
	cout << endl;

	//Test reverse:
	reverse(mylist.begin(), mylist.end());

	//Check the container:
	cout << "Reversed container elements: ";
	for_each(mylist.begin(), mylist.end(), PrintInt);
	cout << endl;

	int iTemp = 0;
	cin >> iTemp;

	return (0);
}