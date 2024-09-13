#include "Set.h"
#include <stdexcept>

Set::Set(const int newSize)
{
	if (newSize <= 0)
		throw std::invalid_argument("Size is not a non-negative numner!\n");
	if(newSize > 20)
		throw std::invalid_argument("Size is too big!\n");
	maximumSize = newSize;
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


