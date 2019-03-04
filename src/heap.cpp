#include "heap.h"
#include "macro.h"
#include <memory>
#include <iostream>

Heap::Heap(bool maxHeapify /* = true */)
    : m_data(nullptr), m_len(0), m_isMaxHeapify(maxHeapify)
{
}

Heap::Heap(double *data, int len, bool maxHeapify /* = true */)
    : m_len(len), m_isMaxHeapify(maxHeapify)
{
    m_data = new double[m_len];
    memcpy(m_data, 0, sizeof(double) * m_len);

    Heapify(data, len);
}

Heap::~Heap()
{
    SAFE_DELETE_ARRAY(m_data);
}

void Heap::Add(double v)
{
    
}

void Heap::Output()
{
    for (int i = 0; i < m_len; i++)
    {
        std::cout << m_data[i] << "  ";
    }
    std::cout << std::endl;
}

void Heap::Heapify(double *data, int len)
{
    for(int i = 0; i < len; i++)
    {
        Add(data[i]);
    }
    
}

void Heap::Swap(int i, int j)
{
    double tmp = m_data[i];
    m_data[i] = m_data[j];
    m_data[j] = tmp;
}