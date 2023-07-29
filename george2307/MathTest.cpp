#pragma once
#include "MathUtil.h"
#include <iostream>

using namespace std;

void CalculateAverage_HappyPath()
{
	std::cout << "CalculateAverage_HappyPath" << std::endl;

	int arr[6] = { 3, 5, 4, 2, 2, 8 };

	float result = CalculateAverage(arr, 6);

	if (result != 4)
	{
		std::cout << "** Test Failed: expected: 4 " << " result: " << result << endl;
	}
	else
	{
		std::cout << " -- Test Passed :) " << endl;
	}
}

void CalculateAverage_WhenArrayIsNull_ShouldThrow()
{
	std::cout << "CalculateAverage_WhenArrayIsNull" << std::endl;
	try
	{
		float result = CalculateAverage(NULL, 6);
	}
	catch (exception& err)
	{
		std::cout << "--- Test Passed :) " << endl;
	}
}
