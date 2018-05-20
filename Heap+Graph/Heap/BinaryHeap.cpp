#include "BinaryHeap.h"

template<typename T>
inline BinaryHeap<T>::BinaryHeap()
{
}

template<typename T>
inline bool BinaryHeap<T>::isEmpty() const
{
	if (TheSize <= 0)	return true;
	else return false;
}

template<typename T>
inline const T & BinaryHeap<T>::FindMin() const
{

	// TODO: insert return statement here
}

template<typename T>
inline void BinaryHeap<T>::insert(const T & x)
{
	if (TheSize >= Capacity)
	{
		return;
	}

	TheSize++;
	NewItem = TheSize - 1;
	TheHeap[NewItem] = x;

	
	while (NewItem != 0 && TheHeap[ParentOf(NewItem)] > TheHeap[NewItem])
	{
		PCSwap(ParentOf(NewItem), NewItem);
		NewItem = ParentOf(Newitem);
	}
}

template<typename T>
inline void BinaryHeap<T>::deleteMin()
{
	int*  Min = TheHeap[TheHeap.begin];
	Min = TheHeap[TheHeap.back];

	WalkDown(&Min);

}

template<typename T>
inline void BinaryHeap<T>::DeleteMin(T & MinValue)
{
	
}

template<typename T>
int BinaryHeap<T>::ParentOf(int Child) //Find the array index of the parent of this node
{
	if (Child == 0) return 0;
	else return Child/2;
}

template<typename T>
int BinaryHeap<T>::LChildOf(int Parent) // Find the array index of the left child of this node
{
	return Parent * 2;
}

template<typename T>
int BinaryHeap<T>::RChildOf(int Parent) // Find the array index of the right child of this node
{
	return Parent * 2 + 1;
}

template<typename T>
void BinaryHeap<T>::PCSwap(int Parent, int Child) // swap a parent and child node
{
	T tempnode = TheHeap[Child];
	TheHeap[Child] = TheHeap[Parent];
	TheHeap[Parent] = TheHeap[tempnode];
	
	return;
}

template<typename T>
inline void BinaryHeap<T>::buildHeap()
{
}

template<typename T>
inline void BinaryHeap<T>::WalkDown(int Index)
{
	while (TheHeap[ParentOf(Index)] >= TheHeap[Index])
	{
		if (TheHeap[LChildOf(Index)] < TheHeap[Index])
		{
			PCSwap(Index, LChildOf(Index));
			Index = LChildOf(Index);
		}
		else if (TheHeap[RChildOf(Index)] < TheHeap[Index])
		{
			PCSwap(Index, RChildOf(Index));
			Index = RChildOf(Index);
		}
		else return;


	}
}
