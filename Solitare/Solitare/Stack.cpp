#include "Stack.h"
# include <iostream>

using namespace std;

Stack::Stack(int InitialXPosition, int InitialYPosition, bool FinalStack)
{
	Final = FinalStack;
	TopCard = nullptr;
	StackXPosition = InitialXPosition;
	StackYPosition = InitialYPosition;

	if (Final)
	{
		SetNextValidSuit(ANY);
		SetNextValidValue(ACE);
	}
}

Stack::~Stack()
{
}

void Stack::Push(Card* NewTopCard)
{
	Length++;
	Card* Pushed = TopCard;

	//connect the new top

		NewTopCard->SetNextCard(Pushed);
		NewTopCard->SetPreviousCard(nullptr);
		NewTopCard->SetHidden(false);
		NewTopCard->SetFaceUp(true);


	TopCard = NewTopCard;
	if (Pushed != nullptr) 
	{
		Pushed->SetPreviousCard(TopCard);


		//-----Set Draw Location
		if (!Final)
		{
			TopCard->SetStartX(Pushed->GetStartX());
			TopCard->SetStartY(Pushed->GetStartY() + CardHeightDifference);
			TopCard->SetLastPositionX(TopCard->GetStartX());
			TopCard->SetLastPositionY(TopCard->GetStartY());
			//-----Set Next Valid Suit/Value
			//		NextValidSuit = TopCard->GetNextValidSuit();
			NextValidValue = TopCard->GetNextValidValue();
			NextValidColour = TopCard->GetNextValidColour();
		}
		else
		{
			TopCard->SetStartX(StackXPosition);
			TopCard->SetStartY(StackYPosition);
			TopCard->SetLastPositionX(TopCard->GetStartX());
			TopCard->SetLastPositionY(TopCard->GetStartY());
			//-----Set Next Valid Suit/Value
			//		NextValidSuit = TopCard->GetNextValidSuit();
			NextValidValue++;
			NextValidSuit = TopCard->GetSuit();
		}


	}
	else
	{
		if (!Final)
		{
			//-----Set Draw Location
			TopCard->SetStartX(StackXPosition);
			TopCard->SetStartY(StackYPosition);
			TopCard->SetLastPositionX(TopCard->GetStartX());
			TopCard->SetLastPositionY(TopCard->GetStartY());

			//-----Set Next Valid Suit/Value
			NextValidValue = TopCard->GetNextValidValue();
			NextValidColour = TopCard->GetNextValidColour();
		}
		else
		{
			TopCard->SetStartX(StackXPosition);
			TopCard->SetStartY(StackYPosition);
			TopCard->SetLastPositionX(TopCard->GetStartX());
			TopCard->SetLastPositionY(TopCard->GetStartY());
			//-----Set Next Valid Suit/Value
			NextValidValue++;
			NextValidSuit = TopCard->GetSuit();
		}
	}
	return;
}

Card* Stack::Pop()
{
	Length--;
	if (!IsEmpty()) {
		Card* Popped = TopCard;
		Card* NewTopCard = nullptr;

		//if TopCard is the last node
		if (Popped->GetNextCard() == nullptr) {
			TopCard = nullptr;
			NextValidColour = ANY;
//			NextValidSuit = ANY;
			NextValidValue = KING;
		}
		else
		{
			NewTopCard = Popped->GetNextCard();
			NewTopCard->SetFaceUp(true);
			NewTopCard->SetPreviousCard(nullptr);

			//-----Set Next Valid Card To New Top Card
			//		NextValidSuit = NewTopCard->GetNextValidSuit();
			NextValidValue = NewTopCard->GetNextValidValue();
			NextValidColour = NewTopCard->GetNextValidColour();
		}

		//-----Disconnect the popped node
		Popped->SetNextCard(nullptr);



		TopCard = NewTopCard;
		return Popped;
	}
	return nullptr;
}

Card* Stack::Peek()
{
	if (!IsEmpty()) {
		return TopCard;
	}
	else return nullptr;
}

bool Stack::IsEmpty()
{
	if (TopCard == nullptr) {
		return true;
	}
	else return false;

}

int Stack::GetNextValidSuit()
{
	return NextValidSuit;
}

int Stack::GetNextValidValue()
{
	return NextValidValue;
}

int Stack::GetNextValidColour()
{
	return NextValidColour;
}

void Stack::SetNextValidSuit(int NewSuit)
{
	NextValidSuit = NewSuit;
}

void Stack::SetNextValidValue(int NewValue)
{
	NextValidValue = NewValue;
}

void Stack::SetNextValidColour(int NewColour)
{
	NextValidColour = NewColour;
}

int Stack::GetStackXPosition()
{
	return StackXPosition;
}

int Stack::GetStackYPosition()
{
	return StackYPosition;
}

int Stack::GetLength()
{
	return Length;
}

