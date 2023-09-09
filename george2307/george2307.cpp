// george2307.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <cstdlib>

#include "Stack.cpp"
#include "MathTest.h"
#include "MathUtil.h"
#include "QueueTest.h"
#include "IntArray.h"
#include "User.h"
#include "PriorityQueueV2.h"

using namespace std;

int EvaluateCommandStack(const std::string& option)
{
    if (option == "create")
    {
    }

    return 0;
}

void PrintOptions()
{
    std::cout << "-- create" << std::endl;
    std::cout << "-- exit" << std::endl;
}

void CreateRepl()
{
    std::cout << "Welcome to my REPL \n";

    //  main loop
    while (true)
    {
        PrintOptions();
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
}

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
    std::cin >> n;
    if (n == 3)
    {
        string c{ "64" };
    }
    else
    {
        std::cout << "0" << endl;
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

int RecursiveBinarySearch(int array[], int left, int right, int element)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        if (array[middle] == element)
        {
            return middle;
        }
        else if (array[middle] < element)
        {
            return RecursiveBinarySearch(array, middle + 1, right, element);
        }
        else
        {
            return RecursiveBinarySearch(array, left, middle - 1, element);
        }
    }

    return -1;
}

int* GenerateRandomIntegers(int minRange, int maxRange, int size)
{
    std::random_device randDev;
    std::mt19937 generator(randDev());

    int* integers = new int[size];

    std::uniform_int_distribution<int> distribution(minRange, maxRange);

    for (int i = 0; i < size; ++i)
    {
        integers[i] = distribution(generator);
    }

    return integers;
}

void TestBubbleSort(int size)
{
    cout << "======= BubbleSort with " << size << " ==========" << endl;
    int* integers = GenerateRandomIntegers(0, 1000, size);
    // Display(integers, size);

    auto startTime1 = std::chrono::high_resolution_clock::now();

    int* sortedIntegers = BubbleSort(integers, size);

    auto endTime1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapedTime1 = endTime1 - startTime1;
    cout << "time elapsed was: " << elapedTime1.count() << " seconds" << endl;
    cout << "=========== || ==========" << endl;
}

void AddTwo(int* x)
{
    *x += 2;
}

void AddTwo(int& x)
{
    x += 2;
}

void Pointers1()
{
    int x = 2;          // stored in memory location 128
    int *q = &x;        // & address-of operator will return 128
    int *ptr_to_x = &x; // 128
    int y = *ptr_to_x;  // * dereference operator - grab 2 from memory address 128 and put it in y
    *ptr_to_x = 5;      // put 5 in memory location  128

    int t, z;
    int* a, b, c;
    
    AddTwo(&x);

    int &r1 = x;
    const int &r2 = x;
    // r2 = 7; // not possible 

    std::cout << &x << std::endl;
    std::cout << &r1 << std::endl;
    std::cout << &y << std::endl;

    AddTwo(r1);

    std::cout << r1 << std::endl;

    int const* p = &x;
    // *p = 6; // not possible

    int *ptr = nullptr; // NULL, 0

    std::cout << sizeof(int *) << std::endl;
    std::cout << sizeof(char *) << std::endl;
    std::cout << sizeof(double *) << std::endl;

    void* v = &x;
    int* i = &x;
    std::cout << v << std::endl;
    std::cout << i << std::endl;

    std::cout << *i << std::endl;
    std::cout << *(int *)v << std::endl;

    int* nx = new int;
    delete nx;
}

User* CreateUser()
{
    User* u = new User(); // on the heap
    return u;
}

void Pointers2()
{
    User* u = CreateUser();
    
    // using the u object here 
    // ...
    // ...

    delete u;
}

void ProcessArray(int nums[], int size)
{

}

void Pointers3()
{
    const int SIZE = 4;
    int x[SIZE] = { 10, 20, 30, 40};


    std::cout << x[0] << std::endl;
    std::cout << x[1] << std::endl;

    std::cout << x << ' ' << &x[0] << std::endl;
    std::cout << x + 1 << ' ' << &x[1] << std::endl;
    std::cout << x + 2 << ' ' << &x[2] << std::endl;

    std::cout << *x << ' ' << x[0] << std::endl;
    std::cout << *(x + 1) << ' ' << x[1] << std::endl;
    std::cout << *(x + 2) << ' ' << x[2] << std::endl;

    int size;
    std::cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    int num_of_rows;
    int num_of_columns;
    std::cout << "Enter number of rows and number of columns: ";
    std::cin >> num_of_rows >> num_of_columns;

    int** arr2 = new int* [num_of_rows];

    for (int i = 0; i < num_of_rows; i++)
    {
        arr2[i] = new int[num_of_columns];
    }

    for (int i = 0; i < num_of_rows; i++)
    {
        for (int j = 0; j < num_of_columns; j++)
        {
            arr2[i][j] = i * j;
        }
    }

    std::cout << " arr2: " << endl;
    for (int i = 0; i < num_of_rows; i++)
    {
        std::cout << '|';
        for (int j = 0; j < num_of_columns; j++)
        {
            std::cout << arr2[i][j] << '|';
        }

        std::cout << std::endl;
    }
}

int Sum(int x, int y)
{
    return x + y;
}

void Pointers4()
{
    std::cout << Sum << std::endl;

    int (*func)(int, int) = Sum;    // C syntax

    auto* func2 = Sum;              // C++ syntax

    std::cout << (*func)(4, 5) << std::endl;
    
    std::cout << func2(4, 5) << std::endl;
}

void Pointers5()
{
    int arr[3] = { 1,2,3 };
    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
}

void Pointers6()
{
    int num_of_rows;
    int num_of_columns;
    std::cout << "Enter number of rows and number of columns: ";
    std::cin >> num_of_rows >> num_of_columns;

    int* arr = new int[num_of_rows * num_of_columns];

    int init = 0;
    for (int i = 0; i < num_of_rows; i++)
    {
        for (int j = 0; j < num_of_columns; j++)
        {
            arr[i * num_of_columns + j] = init++;
        }
    }

    std::cout << " arr: " << endl;
    for (int i = 0; i < num_of_rows; i++)
    {
        std::cout << '|';
        for (int j = 0; j < num_of_columns; j++)
        {
            std::cout << arr[i * num_of_columns + j] << '|';
        }

        std::cout << std::endl;
    }
}

void Pointers7()
{
    User user1;

    User* user2 = new User();
    delete user2;

    User *user3 = (User *)std::malloc(sizeof(User));
    std::free(user3);
}

std::size_t allocated_memory = 0;

void* operator new(std::size_t size)
{
    std::cout << "Memory allocated" << std::endl;
    std::cout << "Allocated memory size: " << size << std::endl;
    
    allocated_memory += size;

    return std::malloc(size);
}

void operator delete(void* memory, std::size_t size)
{
    std::cout << "Memory Deallocated" << std::endl;
    std::cout << "Deallocated memory size : " << size << std::endl;

    allocated_memory -= size;

    std::free(memory);
}

void Pointers8()
{
    int* i = new int;
    // delete i;

    if(allocated_memory > 0)
    {
        std::cout << "There is a memory leak" << std::endl;
    }
}

void DisplayArray(int arr[], int size)
{
    std::cout << "==== ====" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << '[' << i << "] = " << arr[i] <<  std::endl;
    }
}

void Merge(int arr[], int start, int mid, int end, int temp[])
{
    int size1 = mid - start + 1;
    int size2 = end - mid;

    // copy the sub-arrays into the temporary array
    for (int i = 0; i < size1; i++)
    {
        temp[i] = arr[i + start];
    }

    for (int i = 0; i < size2; i++)
    {
        temp[i + size1] = arr[i + mid + 1];
    }

    // merge sorted subarrays into arr
    int l = 0, r = size1, a = start;
    while (l < size1 && r < size1 + size2)
    {
        if (temp[l] < temp[r])
        {
            arr[a++] = temp[l++];
        }
        else
        {
            arr[a++] = temp[r++];
        }
    }

    // copy the remaining elements from left and right into arr
    while (l < size1)
    {
        arr[a++] = temp[l++];
    }

    while (r < size1 + size2)
    {
        arr[a++] = temp[r++];
    }
}

void MergeSort(int arr[], int start, int end, int temp[])
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    MergeSort(arr, start, mid, temp);
    MergeSort(arr, mid + 1, end, temp);

    Merge(arr, start, mid, end, temp);
}

int generateRandom(int low, int high)
{
    return low + rand() % (high - low + 1);
}

int Partition(int arr[], int pivot, int right)
{
    swap(arr[pivot], arr[right]);
    int left = 0;
    for (int i = 1; i < right - 1; i++)
    {
        if (arr[i] < arr[right])
        {
            left++;
            swap(arr[left], arr[i]);
        }
    }

    swap(arr[right], arr[left + 1]);
    return left + 1;
}

void QuickSort(int arr[], int pivot, int n)
{
    if (pivot < n)
    {
        int r = Partition(arr, pivot, n);
        QuickSort(arr, pivot, r - 1);
        QuickSort(arr, r, n - 1);
    }
}

void TestQuickSort()
{
    int arr[] = { 5, 2, 9, 1, 5, 6, 3, 23, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    DisplayArray(arr, n);

    QuickSort(arr, 0, n - 1);

    DisplayArray(arr, n);
}

void TestQuickSort(int size)
{
    cout << "======= QuickSort with " << size << " ==========" << endl;
    int* randomSet = GenerateRandomIntegers(0, size, size);
    // Display(integers, size);

    auto startTime1 = std::chrono::high_resolution_clock::now();

    QuickSort(randomSet, 0, size - 1);

    auto endTime1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapedTime1 = endTime1 - startTime1;
    cout << "time elapsed was: " << elapedTime1.count() << " seconds" << endl;
    cout << "=========== || ==========" << endl;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void TestMergeSort()
{
    const int size1 = 1;
    int arr1[size1] = { 6 };
    int temp1[size1];
    MergeSort(arr1, 0, size1 - 1, temp1);

    const int size2 = 2;
    int arr2[size2] = { 6, 3 };
    int temp2[size2];
    MergeSort(arr2, 0, size2 - 1, temp2);

    const int size3 = 3;
    int arr3[size3] = { 6, 3, 2 };
    int temp3[size3];
    MergeSort(arr3, 0, size3 - 1, temp3);

    const int size = 8;
    int arr[size] = { 6, 3, 5, 1, 4, 8, 2, 7 };
    int temp[size];

    std::cout << "Before merge-sort: " << std::endl;
    DisplayArray(arr, size);
    
    MergeSort(arr, 0, size - 1, temp);
    
    std::cout << "After merge-sort: " << std::endl;
    DisplayArray(arr, size);
}

void TestPQ()
{
    // test the swap function
    int a = 12;
    int b = 10;
    swap(&a, &b);

    // test the priority queue
    PriorityQueueV2 pq(20);
 
    int arr[] = { 5, 18, 10, 27, 4, 16, 8 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrSize; i++)
    {
        pq.Enqueue(arr[i]);
        std::cout << "Enqueued item: " << arr[i] << std::endl;
    }

    for (int i = 0; i < arrSize; i++)
    {
        std::cout << "Dequeued item: " << pq.Dequeue() << std::endl;
    }

    std::cout << "All items are Dequeued" << std::endl;
}

int main()
{
    TestPQ();

    // TestQuickSort();
    // TestQuickSort(100);

    // TestMergeSort();

    /*
    Pointers8(); 
    Pointers7();
    Pointers6();
    Pointers4();
    Pointers3();
    Pointers1();
    */
    /*
    TestBubbleSort(100);
    TestBubbleSort(1000);
    TestBubbleSort(10000);
    TestBubbleSort(20000);
    TestBubbleSort(30000);
    TestBubbleSort(50000);
    TestBubbleSort(100000);

    int size = 10000;
    int* integers = GenerateRandomIntegers(0, 1000, size);
    // Display(integers, size);

    auto startTime1 = std::chrono::high_resolution_clock::now();

    int* sortedIntegers = BubbleSort(integers, size);
    
    auto endTime1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapedTime1 = endTime1 - startTime1;
    cout << "time elapsed is: " << elapedTime1.count() << " seconds" << endl;
    cout << "======= Sorted integers ==========" << endl;
    // Display(integers, size);

    // =================================================

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

    int sortedItems[5] = { 5,7,9,11,17 };
    int result = RecursiveBinarySearch(sortedItems, 0, 4, 11);

    cout << "Recursive binary search result: " << result << endl;
    */
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
