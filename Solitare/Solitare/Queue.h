#include "Card.h"

class Queue {

private:
	Card* Front;
	Card* Back;

public:

	Queue(int InitialXPosition, int InitialYPosition, bool Revealed);
	~Queue();


	//-----Variables
	bool	FaceUp;
	int		QueueXPosition;
	int		QueueYPosition;

	//-----Functions
	void	Enqueue(Card* CardToAdd);
	Card*	Dequeue();
	Card*	Peek();
	bool	IsEmpty();

	int		GetQueueXPosition();
	int		GetQueueYPosition();
};
