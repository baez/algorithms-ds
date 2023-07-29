#pragma once
#include <exception>

// Calculates average for an array of integers
float CalculateAverage(int* array, int size)
{
	if (array == nullptr)
	{
		throw std::exception("CalculateAverage should not be called with array being null");
	}

	float sum = 0;
	for (int i = 0; i < size ; i++)
	{
		sum = sum + array[i];
	}

	return sum / size;
}
