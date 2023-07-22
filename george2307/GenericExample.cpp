#include <iostream>

int findMax(int a, int b)
{
	return (a > b) ? a : b;
}

template <typename T>
T findMax(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T>
bool isEqual(T a, T b)
{
	return (a == b);
}
