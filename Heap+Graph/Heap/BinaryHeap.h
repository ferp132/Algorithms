#pragma once

#ifndef _BinaryHeap_
#define _BinaryHeap_

template <typename T>
class BinaryHeap
{
public:
	BinaryHeap();
	bool isEmpty() const;
	const T& findMin() const;
	void insert(const T& x);
	void deleteMin();
	void DeleteKey(T & KeyValue);
	int ParentOf(int Child);
	int LChildOf(int Parent);
	int RChildOf(int Parent);
	void PCSwap(int Parent, int Child);

private:
	int capacity = 100
	int TheSize; // Number of elements in heap
	vector <T> TheHeap; // The heap array
	void buildHeap();
	void WalkDown(int hole);
};
#endif