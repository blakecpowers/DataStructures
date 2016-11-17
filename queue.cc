#include <iostream>
#include <cstdlib>
#include "queue.h"
using namespace std;

static int incr(int i)
{
	return((i+1)%MAX_LENGTH);
}

CircularQueue::CircularQueue()
{
	Clear();
}

CircularQueue::~CircularQueue()
{
	return;
}

void
CircularQueue::Clear()
{
	for (int i=0; i<MAX_LENGTH; i++)
	{
		delete elem[i];
		elem[i] = NULL;  //we are initializing all values in this array to NULL
	}

	rear = front = 0; 

	return;
}

int
CircularQueue::Empty()
{
	if (rear == front && Front() == NULL) //if rear and front are equal and they are = to NULL then there is nothing there. 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ElementTypePtr
CircularQueue::Front()
{

	return elem[front];    //all this is asking for is the front element
}

int
CircularQueue::Enqueue(ElementTypePtr e)
{
	// if incr(incr(rear))= front then return 0;
	//else empty
	// incr(rear)
	// elem(rear) = e

	if (incr(incr(rear)) == front)    // if the next (next) position is the beginning then we cant add any becasue it's full
	{
		return -1;
	}
	else 
	{
		if (Empty())
		{
			elem[rear] = e;
		}
		else
		{
			rear = incr(rear);
			elem[rear] = e;
			
		}
		return 0;
	}
}

ElementTypePtr
CircularQueue::Dequeue()
{
	ElementTypePtr temp;
	if (Empty())
	{
		return NULL;
	}
	else
	{
		temp = elem[front];
		elem[front] = NULL;
		
		front = incr(front);
		return temp;
	}
}

std::ostream&
operator <<(std::ostream& stream, const CircularQueue& q)
{
	int i;

	stream << "[";
	for (i = q.front; i != incr(q.rear); i = incr(i)) {
		if (q.elem[i] != NULL)
			stream << q.elem[i]->getValue();

		if (i != q.rear)
			std::cout << ",";
	}
	stream << "]";
	return stream;
}
