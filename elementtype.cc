#include <iostream>
#include <cstdlib>
#include "queue.h"

ElementType::ElementType()
{
	val = (-1);
}

ElementType::~ElementType()
{
	return;
}

int
ElementType::getValue()
{
	return val;
}

void
ElementType::setValue(int val)
{
	this->val = val;
}

void
ElementType::operator= (int val)
{
	setValue(val);
}

std::ostream& operator <<(std::ostream& stream, const ElementType& e)
{
	stream << e.val;
	return stream;
}
