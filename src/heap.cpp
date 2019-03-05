#include "heap.h"
#include "macro.h"
#include <memory.h>
#include <iostream>
#include <cmath>

Heap::Heap(bool maxHeapify /* = true */)
    : m_data(nullptr), m_isMaxHeapify(maxHeapify), m_cap(10)
{
    Alloc();
}

Heap::Heap(int *data, int len, bool maxHeapify /* = true */)
    : m_isMaxHeapify(maxHeapify)
{
    m_cap = len * 2;
    Alloc();

    m_len = len;
    for (int i = 0; i < m_len; i++)
    {
        m_data[i] = data[i];
    }

    Heapify();
}

Heap::~Heap()
{
    SAFE_DELETE_ARRAY(m_data);
}

void Heap::Add(int v)
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

void Heap::Heapify()
{
    int height = (int)log2(m_len);
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = pow(2, i); j < pow(2, i + 1); j++)
        {
            TrackDown(j - 1);
        }
    }
}

void Heap::TrackDown(int node)
{
    int height = (int)log2(m_len);
    if (node >= pow(2, height))
    {
        return;
    }

    int left = node * 2 + 1;
    int right = node * 2 + 2;

    int sid;
    int value;

    if (m_isMaxHeapify)
    {
        value = m_data[node] < m_data[left] ? m_data[left] : m_data[node];
        value = value < m_data[right] ? m_data[right] : value;
    }
    else
    {
        value = m_data[node] > m_data[left] ? m_data[left] : m_data[node];
        value = value > m_data[right] ? m_data[right] : value;
    }

    if (value == m_data[node])
    {
        return;
    }

    if (value == m_data[left])
    {
        Swap(node, left);
        TrackDown(left);
    }

    if (value == m_data[right])
    {
        Swap(node, right);
        TrackDown(right);
    }
}

void Heap::TrackUp(int node)
{
}

void Heap::Swap(int i, int j)
{
    int tmp = m_data[i];
    m_data[i] = m_data[j];
    m_data[j] = tmp;
}

void Heap::Alloc()
{
    SAFE_DELETE_ARRAY(m_data);
    m_data = new int[m_cap];
    memcpy(m_data, 0, sizeof(int) * m_cap);
    m_len = 0;
}