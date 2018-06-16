#include "stdafx.h"
#include "Card.h"

//--------------------------------------------------------Constructor
Card::Card(int InitialSuit, int InitialValue, int InitialX, int InitialY)
{
	Revealed		= 1;
	Suit			= InitialSuit;
	Value			= InitialValue;
	StartX			= InitialX;
	StartY			= InitialY;
	EndX			= StartX + CardWidth;
	EndY			= StartY + CardHeight;
	LastPositionX	= StartX;
	LastPositionY	= StartY;

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
	EndX = NewX + CardWidth;
}

void Card::SetStartY(int NewY)
{
	StartY = NewY;
	EndY = NewY + CardHeight;
}

void Card::SetEndX(int NewX)
{
	EndX = NewX;
}

void Card::SetEndY(int NewY)
{
	EndY = NewY;
}

void Card::SetPickUpWidth(int NewWidth)
{
	PickUpWidth = NewWidth;
}

void Card::SetPickUpHeight(int NewHeight)
{
	PickUpHeight = NewHeight;
}

void Card::SetLastPositionX(int NewX)
{
	LastPositionX = NewX;
}

void Card::SetLastPositionY(int NewY)
{
	LastPositionY = NewY;
}

//--------------------------------------------------------Draw
void Card::Draw(HDC hdc)
{
	//-----Load Bitmap
	if (Revealed)
	{
		BitmapHandle = (HBITMAP)::LoadImage(NULL, L"Classic_Cards13x4x560x780.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	else
	{
		BitmapHandle = (HBITMAP)::LoadImage(NULL, L"HearthStone_CardBack_ReSized.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}

	//-----Verify Loading
	if (BitmapHandle == NULL)
	{
		MessageBox(NULL, L"Load Image Failed", L"Error", MB_OK);
		GetLastError();
		return;
	}

	//-----Create Compatable Device Context "DC"
	LocalDC = CreateCompatibleDC(hdc);
	//-----Verify DC was Created
	if (BitmapHandle == NULL)
	{
		MessageBox(NULL, L"Create DC Failed", L"Error", MB_OK);
		return;
	}

	//-----Create Bitmap Structure
	int Return = GetObject(BitmapHandle, sizeof(BITMAP), &BitMapStructure);
	//-----Check Fail
	if (!Return)
	{
		MessageBox(NULL, L"GetObject() Failed", L"Error", MB_OK);
		return;
	}

	//-----Select the loaded bitmap into the DC
	OldBitmapHandle = (HBITMAP)::SelectObject(LocalDC, BitmapHandle);
	if (OldBitmapHandle == NULL)
	{
		MessageBox(NULL, L"Select Object Failed", L"Error", MB_OK);
		return;
	}

	//-----Actual Drawing
	if (Revealed) 
	{
		
		Return = BitBlt(hdc, StartX, StartY, CardWidth, CardHeight, LocalDC, CardWidth * Suit, CardHeight * Value, SRCCOPY);
			
	}
	else
	{
		Return = BitBlt(hdc, StartX, StartY, CardWidth, CardHeight, LocalDC, 0, 0, SRCCOPY);
		
	}
	//-----Check Fail
	if (!Return)
	{
		MessageBox(NULL, L"GetObject() Failed", L"Error", MB_OK);
		return;
	}

	//Deselect Objects
	SelectObject(LocalDC, OldBitmapHandle);
	DeleteDC(LocalDC);
	DeleteObject(BitmapHandle);
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

int Card::GetPickUpWidth()
{
	return PickUpWidth;
}

int Card::GetPickUpHeight()
{
	return PickUpHeight;
}

int Card::GetLastPositionX()
{
	return LastPositionX;
}

int Card::GetLastPositionY()
{
	return LastPositionY;
}

