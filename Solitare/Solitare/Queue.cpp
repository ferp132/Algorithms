#include "Queue.h"

Queue::Queue(int InitialXPosition, int InitialYPosition, bool Revealed)
{
	//-----Set the cards face up or not
	FaceUp = Revealed;

	//-----Set Position on canvas
	QueueXPosition = InitialXPosition;
	QueueYPosition = InitialYPosition;


	Front = nullptr;
	Back = nullptr;

}

Queue::~Queue()
{
}

void Queue::Enqueue(Card* CardToAdd)
{
	Card* NextInLine = nullptr;
	//Set The Cards XY Position to the queue
	CardToAdd->SetStartX(QueueXPosition);
	CardToAdd->SetStartY(QueueYPosition);
	CardToAdd->SetLastPositionX(QueueXPosition);
	CardToAdd->SetLastPositionY(QueueYPosition);

	if (Front == nullptr)	
	{
		Front = CardToAdd;

		Front->SetNextCard(Back);
		Front->SetPreviousCard(nullptr);


			//------Make The Card at the front of the queue Visible but face down
		CardToAdd->SetFaceUp(FaceUp);
		CardToAdd->SetHidden(false);
		return;
	}
	else if (Back == nullptr) 
	{
		Back = CardToAdd;

		Back->SetPreviousCard(Front);
		Back->SetNextCard(nullptr);
		Front->SetNextCard(Back);

		if (FaceUp)
		{
			CardToAdd->SetFaceUp(true);
			CardToAdd->SetHidden(false);

			CardToAdd->SetStartX(QueueXPosition + 35);
			CardToAdd->SetStartY(QueueYPosition);
			CardToAdd->SetLastPositionX(QueueXPosition + 35);
			CardToAdd->SetLastPositionY(QueueYPosition);

			return;
		}
	}
	else 
	{
		NextInLine = Back;
		CardToAdd->SetPreviousCard(NextInLine);
		CardToAdd->SetNextCard(nullptr);
		NextInLine->SetNextCard(CardToAdd);
		Back = CardToAdd;

		if (FaceUp)
		{
			CardToAdd->SetFaceUp(true);
			CardToAdd->SetHidden(false);

			CardToAdd->SetStartX(QueueXPosition + 70);
			CardToAdd->SetStartY(QueueYPosition);
			CardToAdd->SetLastPositionX(QueueXPosition + 70);
			CardToAdd->SetLastPositionY(QueueYPosition);
			return;
		}
	}

	//-----Set The Card at the back to Face Down and not visible
	CardToAdd->SetHidden(true);

	return;
}

Card* Queue::Dequeue()
{
	if (!IsEmpty()) {

		Card* Dequeued = Front;
		Front->SetPreviousCard(nullptr);

		if (Front->GetNextCard() != nullptr)
		{
			Front = Front->GetNextCard();
			Front->SetFaceUp(FaceUp);
			Front->SetHidden(false);

		}
		else Front = nullptr;

		Dequeued->SetNextCard(nullptr);
		Dequeued->SetPreviousCard(nullptr);

		return Dequeued;
	}
	return false;
}

Card* Queue::Peek()
{
	if (!IsEmpty()) {
		return Front;
	}
	return nullptr;
}

bool Queue::IsEmpty()
{
	if (Front == nullptr) return true;
	else return false;
}

int Queue::GetQueueXPosition()
{
	return QueueXPosition;
}

int Queue::GetQueueYPosition()
{
	return QueueYPosition;
}
