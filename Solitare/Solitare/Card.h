#ifndef __CARD_H__
#define __CARD_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>


class Card
{
public:
	//-----Constructor/Deconstructor
//	CStamp(HINSTANCE hInstance, wchar_t* filename, int, int);
	Card(int InitialSuit, int InitialValue, int InitialX, int InitialY, bool SetRevealed);
	virtual ~Card();

	//-----Set Values
	void	SetSuit		(int NewSuit);
	void	SetValue	(int NewValue);
	void	SetStack	(int NewStack);
	void	SetRevelaled();

	//-----Set Dimensions
	void	SetStartX		(int NewX);
	void	SetStartY		(int NewY);
	void	SetEndX			(int NewX);
	void	SetEndY			(int NewY);
	void	SetPickUpWidth	(int NewX);
	void	SetPickUpHeight	(int NewY);

	//-----Set Locations
	void	SetLastPositionX(int NewX);
	void	SetLastPositionY(int NewY);

	//-----Draw
	void	Draw(HDC hdc);

	//-----Get Values
	int		GetSuit		();
	int		GetValue	();
	int		GetStack	();
	int		GetRevealed	();

	//-----Get Dimensions
	int		GetStartX		();
	int		GetStartY		();
	int		GetEndX			();
	int		GetEndY			();
	int		GetPickUpWidth	();
	int		GetPickUpHeight	();

	//-----Get Locations
	int	    GetLastPositionX();
	int 	GetLastPositionY();

	//-----Stack Variables
	Card* NextCard;
	Card* PreviousCard;
	int NextValidSuit;
	int NextValidValue;

	//-----Stack Functions
	void	SetNextCard		(Card* NewNextCard);
	void	SetPreviousCard	(Card* NewPreviousCard);
	Card*	GetNextCard		() const;
	Card*	GetPreviousCard	() const;
	int GetNextValidSuit();
	int GetNextValidValue();
	void SetNextValidSuit(int NewSuit);
	void SetNextValidValue(int NewValue);

private:
	//-----Variables
	int		Suit;
	int		Value;
	int		CurrentStack;
	bool	Revealed;

	//-----Dimensions
	int			StartX;
	int			StartY;
	int			EndX;
	int			EndY;	
	//-----Card Size


	//----Pick Up Point
	int		PickUpWidth;
	int		PickUpHeight;

	//-----Locations
	int		LastPositionX;
	int		LastPositionY;

	//-----Storage For Bitmap
	HBITMAP BitmapHandle;
	HBITMAP OldBitmapHandle;
	BITMAP	BitMapStructure;
	HDC		LocalDC;

};

#endif