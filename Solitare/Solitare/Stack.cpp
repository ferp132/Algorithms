#include "Stack.h"
# include <iostream>

using namespace std;

Stack::Stack(int InitialXPosition, int InitialYPosition)
{
	TopCard = nullptr;
	StackXPosition = InitialXPosition;
	StackYPosition = InitialYPosition;

}

Stack::~Stack()
{
}

void Stack::Push(Card* NewTopCard)
{
	Card* Pushed = TopCard;

	//connect the new top
	NewTopCard->SetNextCard(Pushed);
	NewTopCard->SetPreviousCard(nullptr);

	TopCard = NewTopCard;
	if (Pushed != nullptr) 
	{
		Pushed->SetPreviousCard(TopCard);

		//-----Set Draw Location
		TopCard->SetStartX(Pushed->GetStartX());
		TopCard->SetStartY(Pushed->GetStartY() + CardHeightDifference);
		TopCard->SetLastPositionX(TopCard->GetStartX());
		TopCard->SetLastPositionY(TopCard->GetStartY());

		//-----Set Next Valid Suit/Value
		NextValidSuit = TopCard->GetNextValidSuit();
		NextValidValue = TopCard->GetNextValidValue();
	}
	else
	{
		//-----Set Draw Location
		TopCard->SetStartX(StackXPosition);
		TopCard->SetStartY(StackYPosition);
		TopCard->SetLastPositionX(TopCard->GetStartX());
		TopCard->SetLastPositionY(TopCard->GetStartY());

		//-----Set Next Valid Suit/Value
		NextValidSuit = TopCard->GetNextValidSuit();
		NextValidValue = TopCard->GetNextValidValue();
	}
	return;
}

void Stack::Pop()
{
	if (!IsEmpty()) {
		Card* Popped = TopCard;
		//if TopCard is the last node
		if (Popped->GetNextCard() == nullptr) {
			//dataref = Top->GetData();
			//Top->SetData(0);
			//TopCard= nullptr;
			NextValidSuit = ANY;
			NextValidValue = KING;
			return;
		}


		Card* NewTopCard= Popped->GetNextCard();

		//-----Disconnect the popped node
		NewTopCard->SetPreviousCard(nullptr);
		Popped->SetNextCard(nullptr);

		//-----Set Next Valid Card To New Top Card
		NextValidSuit = NewTopCard->GetNextValidSuit();
		NextValidValue = NewTopCard->GetNextValidValue();

		TopCard= NewTopCard;
		return;
	}
	return;
}

Card* Stack::Peek()
{
	if (!IsEmpty()) {
		return TopCard;
	}
}

bool Stack::IsEmpty()
{
	if (TopCard == nullptr) {
		return true;
	}
	else return false;

}

int Stack::GetStackXPosition()
{
	return StackXPosition;
}

int Stack::GetStackYPosition()
{
	return StackYPosition;
}

