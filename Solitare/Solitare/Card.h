#ifndef __CARD_H__
#define __CARD_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>


class Card
{
public:
	//-----Constructor/Deconstructor
			Card(int InitialSuit, int InitialValue);
			~Card();

	//-----Set Values
	void	SetSuit(int NewSuit);
	void	SetValue(int NewValue);
	void	SetStack(int NewStack);
	void	SetRevelaled();

	//-----Set Dimensions
	void	SetStartX(int NewX);
	void	SetStartY(int NewY);
	void	SetEndX(int NewX);
	void	SetEndY(int NewY);

	//-----Draw
	void	Draw(HDC hdc);

	//-----Get Values
	int		GetSuit();
	int		GetValue();
	int		GetStack();
	int		GetRevealed();

	//-----Get Dimensions
	int		GetStartX();
	int		GetStartY();
	int		GetEndX();
	int		GetEndY();

private:
	//-----Variables
	int		Suit;
	int		Value;
	int		CurrentStack;
	bool	Revealed;

	//-----Dimensions
	int		StartX;
	int		StartY;
	int		EndX;
	int		EndY;



	//-----Storage For Bitmap
	HBITMAP BitMapHandle;
	BITMAP	BitMapStructure;

};

#endif