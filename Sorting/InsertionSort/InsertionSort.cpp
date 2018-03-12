#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int const length = 5;
	int ToSort[length] = { 2, 5, 1, 3, 4 };
	int Temp = 0;
	int step = 1;

	cout << "Before sort: " << endl << endl;
	for (int j = 0; j < length; j++)\
	{
		cout << ToSort[j];
	}

	for (int i = 0; i < length - 1; i++)
	{
		Temp = ToSort[step];
		for (int k = step - 1; k >= 0; --k)
		{
			
			if (ToSort[k] > Temp)
			{
				ToSort[k + 1] = ToSort[k];
			}
			else
			{
				ToSort[step] = Temp;
			}
			
		}
		step++;
	}
	

	cout << endl << endl << "After sort: " << endl << endl;
	for (int j = 0; j < length; j++)\
	{
		cout << ToSort[j];
	}

	int wait;
	cin >> wait;
	return 0;
}

