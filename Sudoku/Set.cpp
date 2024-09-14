#include "Set.h"
#include <stdexcept>

Set::Set(const int newSize)
{
	if (newSize <= 0)
		throw std::invalid_argument("Size is not a non-negative numner!\n");
	if(newSize > 20)
		throw std::invalid_argument("Size is too big!\n");
	maximumSize = newSize + 1; //position 0 is a dummy element
	data = new bool[maximumSize];
	for (int i = 0; i < maximumSize; i++)
		data[i] = false;
}

void Set::insert(const int element)
{
	if (element > maximumSize || element < 0)
		throw std::invalid_argument("Element does not fit in the set!\n");
	data[element] = true;
}

void Set::remove(const int element)
{
	if (element > maximumSize || element < 0)
		throw std::invalid_argument("Element does not fit in the set!\n");
	data[element] = false;
}

bool Set::isFull() const
{
	for (int i = 1; i < maximumSize; i++)
		if (!data[i])
			return false;
	return true;
}

void Set::clear()
{
	for (int i = 0; i < maximumSize; i++)
		data[i] = false;
}


