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
	//-----Load Bitmap
	BitMapHandle = (HBITMAP)::LoadImage(NULL, L"Classic_Cards13x4x560x780.png", IMAGE_BITMAP, 560, 780, LR_LOADFROMFILE);
	//-----Verify Loading
	if (BitMapHandle == NULL)
	{
		MessageBox(NULL, L"Load Image Failed", L"Error", MB_OK);
		return;
	}

	//-----Create Compatable Device Context "DC"
	LocalDC = CreateCompatibleDC(hdc);
	//-----Verify DC was Created
	if (BitMapHandle == NULL)
	{
		MessageBox(NULL, L"Create DC Failed", L"Error", MB_OK);
		return;
	}

	//-----Create Bitmap Structure
	int Return = GetObject(BitMapHandle, sizeof(BITMAP), &BitMapStructure);
	//-----Check Fail
	if (!Return)
	{
		MessageBox(NULL, L"GetObject() Failed", L"Error", MB_OK);
		return;
	}

	//-----Actual Drawing
	Return = BitBlt(hdc, StartX, StartY, 560, 780, LocalDC, 560 * Value, 780 * Suit, SRCCOPY);
	//-----Check Fail
	if (!Return)
	{
		MessageBox(NULL, L"GetObject() Failed", L"Error", MB_OK);
		return;
	}

	//TODO: Deselect Objects
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

