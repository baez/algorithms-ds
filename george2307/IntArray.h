#pragma once

#include "IndexOutOfBoundException.h"

class IntArray
{
private:
    int* m_ptr{nullptr};
    int m_size{ 0 };

    bool IsValidIndex(int index) const
    {
        return (index >= 0 && index < m_size);
    }

public:

    IntArray(int size)
    {
        if (size != 0)
        {
            m_ptr = new int[size] {};
            m_size = size;
        }
    }

    IntArray(const IntArray& source)
    {
        if (!source.IsEmpty())
        {
            m_size = source.m_size;
            m_ptr = new int[m_size];

            for (int i = 0; i < m_size; i++)
            {
                m_ptr[i] = source.m_ptr[i];
            }
        }
    }

    // disable Compiler-generated copy constructor
    // IntArray(const IntArray&) = delete;

    IntArray& operator=(const IntArray& source)
    {
        if (&source != this)
        {
            m_size = source.m_size;
            m_ptr = new int[m_size];

            for (int i = 0; i < m_size; i++)
            {
                m_ptr[i] = source.m_ptr[i];
            }
        }

        return *this;
    }

    int Size() const
    {
        return m_size;
    }

    bool IsEmpty() const
    {
        return (m_size == 0);
    }

    ~IntArray()
    {
        delete[] m_ptr;
    }

    int operator[](int index) const
    {
        if (!IsValidIndex(index))
        {
            throw IndexOutOfBoundException{};
        }

        return m_ptr[index];
    }

    int& operator[](int index)
    {
        if (!IsValidIndex(index))
        {
            throw IndexOutOfBoundException{};
        }

        return m_ptr[index];
    }
};

std::ostream& operator<<(std::ostream& os, const IntArray& arr)
{
    os << "{ ";
    for (int i = 0; i < arr.Size(); i++)
    {
        os << arr[i] << ' ';
    }
    
    os << '}';

    return os;
}
