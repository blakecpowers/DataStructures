#ifndef __QUEUE_H
#define __QUEUE_H


#include <iostream>


#define MAX_LENGTH	8


class ElementType {
private:
	int val;

public:
	ElementType();			// Constructor
	~ElementType();			// Destructor

	int getValue();			// Getter
	void setValue(int val);		// Setter
	void operator=(int val);	// Assignment operator overload

	void Print();
					// Output operator overload
	friend std::ostream& operator<<
		(std::ostream& stream, const ElementType& e);
};

typedef class ElementType *ElementTypePtr;

class CircularQueue {
private:
	ElementTypePtr elem[MAX_LENGTH];
	int front, rear;

public:
	CircularQueue();		// Constructor
	~CircularQueue();		// Destructor

	void Clear();			// MAKENULL
	int Empty();			// 1 if empty, 0 otherwise
	ElementTypePtr Front();		// Return ptr to front element
	int Enqueue(ElementTypePtr);	// ENQUEUE
	ElementTypePtr Dequeue();	// DEQUEUE

					// Output operator overload
	friend std::ostream& operator<<
		(std::ostream& stream, const CircularQueue& q);
};

typedef class CircularQueue *CircularQueuePtr;


#endif
