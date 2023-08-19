// george2307.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

#include <string>
#include "Stack.cpp"
#include "MathTest.h"
#include "MathUtil.h"
#include "QueueTest.h"
#include "IntArray.h"

// Rearranging an Array of positive and negative numbers
// Input: [-1, 7, 0, 23, -9, -12, 4]
// Output: negative values to come first (left), zero 0 and the positive values on the right
//         example output: [-1, -9, -12, 7, 0, 23, 4]
// 
int* ReArrange(int array[], int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            if (i != k)
            {
                std::swap(array[i], array[k]);
            }

            k++;
        }
    }

    return array;
}

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// [1, 7, 0, 23, 9, 12, 4]
// Simplest sorting is Bubble Sort
// Goes through the set of items
//  { 1, 7, 0, 23, 9, 12, 4 };
int* BubbleSort(int* arr, int size)
{
    for (int k = 0; k < size - 1; k++)
    {
        bool didSwap = false;
        for (int i = 0; i < size - k - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                didSwap = true;
            }
        }

        if (!didSwap)
        {
            break;
        }
    }

    return arr;
}

int* InsertionSort(int* arr, int size)
{
    for (int k = 1; k < size; k++)
    {
        int temp = arr[k];
        int i = k;
        while (i > 0 && arr[i - 1] >= temp)
        {
            arr[i] = arr[i - 1];
            i--;
        }

        arr[i] = temp;
    }

    return arr;
}

int* SelectionSort(int* arr, int size)
{
    int min = 0;
    for (int k = 0; k < size - 1; k++)
    {
        min = k;
        for (int i = k + 1; i < size; i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        
        if (min != k)
        {
            swap(arr[k], arr[min]);
        }
    }

    return arr;
}

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

string TryToConvert()
{
    int n{1}; // int n = 1;
    cin >> n;
    if (n == 3)
    {
        string c{ "64" };
    }
    else
    {
        cout << "0" << endl;
    }

    return "";
    // cout << c << '\n'; 
    // return c;
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

void Display(int arr[], int size)
{
    cout << ' ';
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int arr6[7] = { 1, 7, 0, 23, 9, 12, 4 };
    cout << "Bubble sort" << endl;
    Display(arr6, 7);

    auto startTime = std::chrono::high_resolution_clock::now();
    int* res6 = BubbleSort(arr6, 7);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapedTime = endTime - startTime;
    cout << "time elapsed is: " << elapedTime.count() << " seconds" << endl;

    Display(res6, 7);

    int arr7[7] = { 1, 7, 0, 23, 9, 12, 4 };
    cout << "Selection sort" << endl; 
    Display(arr7, 7);
    int* res7 = SelectionSort(arr7, 7);
    Display(res7, 7);

    int arr8[7] = { 1, 7, 0, 23, 9, 12, 4 };
    cout << "Insertion sort" << endl;
    Display(arr8, 7);
    int* res8 = InsertionSort(arr8, 7);
    Display(res8, 7);

    int arr5[7] = { -1, 7, 0, 23, -9, -12, 4 };
    int* res5 = ReArrange(arr5, 7);


    IntArray arr1{ 4 };

    cout << arr1[0] << std::endl;

    arr1[0] = 10;
    arr1[2] = 23;
    arr1[1] = 19;
    arr1[3] = 89;

    // arr1[10] = 90; this line should throw an exception

    IntArray arr2 = arr1;

    cout << "arr1: " << arr1 << std::endl;

    arr2[3] = 209;

    cout << "arr2: " << arr2 << std::endl;
}

/*

Lab: add the number of iterations for each search and print it to the console.
Add a loop to the user input 
Exit when user enters 0

*/

void TestRecursiveFuncs()
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



