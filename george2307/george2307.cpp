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



