#include "stdafx.h"
#include "Card.h"

//--------------------------------------------------------Constructor
Card::Card(int InitialSuit, int InitialValue)
{
	Revealed		= 0;
	Suit			= InitialSuit;
	Value			= InitialValue;
}

//--------------------------------------------------------Destructor
Card::~Card()
{
}

//--------------------------------------------------------Set Values
void Card::SetSuit(int NewSuit)
{
	Suit = NewSuit;
}

void Card::SetValue(int NewValue)
{
	Value = NewValue;
}

void Card::SetStack(int NewStack)
{
	CurrentStack = NewStack;
}

void Card::SetRevelaled()
{
	Revealed = true;
}


//--------------------------------------------------------Set Dimensions
void Card::SetStartX(int NewX)
{
	StartX = NewX;
}

void Card::SetStartY(int NewY)
{
	StartY = NewY;
}

void Card::SetEndX(int NewX)
{
	EndX = NewX;
}

void Card::SetEndY(int NewY)
{
	EndY = NewY;
}

//--------------------------------------------------------Draw
void Card::Draw(HDC hdc)
{
	BitMapHandle = (HBITMAP)::LoadImage(NULL, L"Classic_Cards13x4x560x780.png", IMAGE_BITMAP, 560, 780, LR_LOADFROMFILE);
}

//--------------------------------------------------------Return Values
int Card::GetSuit()
{
	return Suit;
}

int Card::GetValue()
{
	return Value;
}

int Card::GetStack()
{
	return CurrentStack;
}

int Card::GetRevealed()
{
	return Revealed;
}

//--------------------------------------------------------Return Dimensions
int Card::GetStartX()
{
	return StartX;
}

int Card::GetStartY()
{
	return StartY;
}

int Card::GetEndX()
{
	return EndX;
}

int Card::GetEndY()
{
	return EndY;
}

