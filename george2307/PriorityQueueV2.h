#pragma once

#include <exception>
#include <iostream>
using namespace std;

// Max Priority Queue
// Implements a Max priority queue baced by an array-based heap

class PriorityQueueV2
{
	int m_currentSize = 0;
	int m_maxSize = 0;
	int *m_heap;

private:
	int GetParentIndex(int index)
	{
		return (index - 1) / 2;
	}

	int GetLeftChildIndex(int index)
	{
		return 2 * index + 1;
	}

	int GetRightChildIndex(int index)
	{
		return 2 * index + 2;
	}

	void TryBubbleUp(int currentIndex)
	{
		int parentIndex = GetParentIndex(currentIndex);
		while (currentIndex > 0 && m_heap[currentIndex] > m_heap[parentIndex])
		{
			std::swap(m_heap[parentIndex], m_heap[currentIndex]);
			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

	void TryMoveDown(int currentIndex)
	{
		int tempIndex = currentIndex;
		int rightIndex = GetRightChildIndex(currentIndex);
		int leftIndex = GetLeftChildIndex(currentIndex);

		if (leftIndex < m_currentSize && m_heap[leftIndex] > m_heap[currentIndex])
		{
			tempIndex = leftIndex; // save the larger value's index
		}

		if (rightIndex < m_currentSize && m_heap[rightIndex] > m_heap[tempIndex])
		{
			tempIndex = rightIndex; // again save the larger value's index
		}

		if (tempIndex != currentIndex) // we have seen a larger value, we need to swap
		{
			std::swap(m_heap[tempIndex], m_heap[currentIndex]);
			TryMoveDown(tempIndex);
		}
	}

public:
	PriorityQueueV2(int maxSize)
	{
		m_maxSize = maxSize;
		m_heap = new int[m_maxSize];
	}

	~PriorityQueueV2()
	{
		delete[] m_heap;
	}

	void Enqueue(int item)
	{
		if (IsFull())
		{
			throw std::overflow_error("Priority Queue is Full");
		}

		m_heap[m_currentSize] = item;
		
		TryBubbleUp(m_currentSize);
		
		m_currentSize++;
	}

	int Dequeue()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("Priority Queue is Empty");
		}

		int topItem = m_heap[0];

		m_heap[0] = m_heap[m_currentSize - 1];
		m_currentSize--;

		TryMoveDown(0);

		return topItem;
	}

	int Peek()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("Priority Queue is Empty");
		}

		return m_heap[0];
	}

	bool IsFull()
	{
		return (m_maxSize == m_currentSize);
	}

	bool IsEmpty()
	{
		return (m_currentSize == 0);
	}
};