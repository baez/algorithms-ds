#include "Queue.h"
#include <iostream>

using namespace std;

void Dequeue_WhenItemsEnqueued_ShouldReturnFirstItem()
{
    std::cout << "Dequeue_WhenItemsEnqueued_ShouldReturnFirstItem" << std::endl;

    Queue<int> q(10, 0);
    q.Enqueue(15);
    q.Enqueue(78);
    q.Enqueue(101);

    int item = q.Dequeue();
    
    if (item == 15)
    {
        std::cout << "--- Test Passed :)" << endl;
    }
    else
    {
        std::cout << "** Test Failed: expected: 15 " << " result: " << item << endl;
    }
}