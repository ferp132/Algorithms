#ifndef __STACK_H__
#define __STACK_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "Card.h"

enum SUIT
{
	CLUBS = 0,
	DIAMONDS = 1,
	HEARTS = 2,
	SPADES = 3,
	ANY = 4
};

enum CARDNAME
{
	ACE = 0,
	TWO = 1,
	THREE = 2,
	FOUR = 3,
	FIVE = 4,
	SIX = 5,
	SEVEN = 6,
	EIGHT = 7,
	NINE = 8,
	TEN = 9,
	JACK = 10,
	QUEEN = 11,
	KING = 12
};

enum CARDSIZE
{
	CARDWIDTH = 140,
	CARDHEIGHT = 195
};

class Stack 
{
private:
	Card* TopCard;

public:
	Stack(int InitialXPosition, int InitialYPosition);
	~Stack();

	//-----Variables For Cards
	int		NewTopX;
	int		NewTopY;
	int		NextValidSuit;
	int		NextValidValue;
	int const  CardHeightDifference = 35;

	//-----Variables For Stack Position
	int		StackXPosition;
	int		StackYPosition;


	//-----Functions
	void	Push(Card* NewTopCard);
	void	Pop();
	Card*	Peek();
	bool	IsEmpty();

	//-----Functions For Get
	int GetStackXPosition();
	int GetStackYPosition();
};

#endif