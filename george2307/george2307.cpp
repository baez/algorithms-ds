// george2307.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

#include <string>
#include "Stack.cpp"
#include "MathTest.h"
#include "MathUtil.h"
#include "QueueTest.h"

int Factorial(int n)
{
    /* base check */
    if (n == 0)
    {
        return 1;
    }

    /* call self  f(4) => 4 * 3 * 2 * 1 */
    return n * Factorial(n - 1);
}

/*
Fibonacci: each number is calculated by adding the previous two numbers
0, 1, 1, 2, 3, 5, 8

Write a recursive function to calculate fibonacci of n

int Fibonacci(int n)
int result = Fibpnacci(3)

*/

int Fibonacci(int n)
{
    // base case
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

double Power(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1.0;
    }
    else if (exponent < 0)
    {
        return 1.0 / Power(base, -exponent);
    }
    else
    {
        return base * Power(base, exponent - 1);
    }
}

int BinarySearch(int element, const int* v, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2; // find the mid-point

        if (v[middle] == element)
        {
            return middle; // element found
        }
        else if (v[middle] < element)
        {
            left = middle + 1;
        }
        else if (v[middle] > element)
        {
            right = middle - 1;
        }
    }

    return -1;
}

/*

Lab: add the number of iterations for each search and print it to the console.
Add a loop to the user input 
Exit when user enters 0

*/


int main()
{
    cout << "Calculate base:";
    int b;
    cin >> b;

    cout << "To the power of:";
    int p;
    cin >> p;

    int powerOfRes = Power(b, p);
    cout << "Power result: " << powerOfRes << endl;

    cout << "------------------------------------------" << endl;

    cout << "Calculate Fibonacci for:";
    int q;
    cin >> q;
    int rfib = Fibonacci(q);
    cout << "Factorial of " << q << " is: " << rfib << endl;

    cout << "------------------------------------------" << endl;

    cout << "Calculate Factorial for:";
    int f;
    cin >> f;

    int res = Factorial(f);
    cout << "Factorial of " << f << " is: " << res << endl;

    cout << "------------------------------------------" << endl;

    vector<int> v{ 11, 22, 33, 44, 55, 66, 77, 88, 99, 111, 121, 131, 220, 250, 300, 350 };

    cout << "Element to search for:";
    int x;
    cin >> x;

    int pos = BinarySearch(x, v.data(), v.size());

    if (pos == -1)
    {
        cout << "item not found" << endl;
    }
    else
    {
        cout << "item found at: " << pos << endl;
    }

    /*
    CalculateAverage_HappyPath();
    CalculateAverage_WhenArrayIsNull_ShouldThrow();
    Dequeue_WhenItemsEnqueued_ShouldReturnFirstItem(); */
}

/*
int EvaluateCommandStack(const std::string& option)
{
    if (option == "create")
    {

        // create stack
        Stack<int> intStack;
        Stack<char*> charPtrStack;

    }

    return 0;
}

void PrintOptionsStack()
{
    std::cout << "-- create" << std::endl;
    std::cout << "-- exit" << std::endl;
}
*/

/*
    std::cout << "Welcome to my REPL \n";

    //  main loop
    while (true)
    {
        PrintOptionsStack();
        std::cout << "Please Enter Option: ";

        std::string input;
        std::getline(std::cin, input);
        if (input == "exit")
        {
            break;
        }

        EvaluateCommandStack(input);
    }

    std::cout << "Thanks and goodbye!" << std::endl;




*/



