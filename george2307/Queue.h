#pragma once

template<typename T>
class Queue
{
	T* m_array;
	int m_head;
	int m_currentSize;
	int m_tail;
	int m_maxLength;
	T m_defaultValue;

public:
	Queue(int maxLength, T defaultValue) :
		m_head(0), m_tail(0), m_currentSize(0)
	{
		m_maxLength = maxLength;
		m_array = new T[maxLength];
		m_defaultValue = defaultValue;

		Initialize();
	}

	void Initialize()
	{
		for (int i = 0; i < m_maxLength; i++)
		{
			m_array[i] = m_defaultValue;
		}
	}

	void Enqueue(T item)
	{
		if (IsFull())
		{
			throw new exception("Queue::Enqueue - queue is full.");
		}

		if (m_tail == m_maxLength - 1)
		{
			m_tail = 0;
		}
		else
		{
			m_tail++;
		}

		m_array[m_tail] = item;
		m_currentSize++;
	}

	T Dequeue()
	{
		if (m_currentSize == 0)
		{
			throw new exception("Queue::Dequeue - queue is empty.")
		}

		T value = m_array[m_head];
		m_array[m_head] = m_defaultValue;

		if (m_head == m_maxLength - 1)
		{
			m_head = 0;
		}

		m_head++;
		m_currentSize--;
	}

	bool IsFull()
	{
		return (m_maxLength == m_currentSize);
	}
};
