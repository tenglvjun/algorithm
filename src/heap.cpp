#include "heap.h"
#include "macro.h"
#include <assert.h>
#include <cmath>
#include "tools.h"

Heap::Heap(bool maxHeapify /* = true */)
    : ContinueContainer(), m_isMaxHeapify(maxHeapify)
{
}

Heap::Heap(int *data, int len, bool maxHeapify /* = true */)
    : ContinueContainer(data, len), m_isMaxHeapify(maxHeapify)
{
    Heapify();
}

Heap::~Heap()
{
}

void Heap::PushBack(const int v)
{
    ContinueContainer::PushBack(v);
    TrackUp(m_len - 1);
}

int Heap::PopFront()
{
    Swap(m_data, 0, (m_len - 1));
    int value = ContinueContainer::Erase(m_len - 1);
    TrackDown(0);
    return value;
}

void Heap::Sort()
{
    int len = m_len;
    int *buf = new int[len];
    int idx = 0;
    while (m_len > 0)
    {
        buf[idx++] = PopFront();
    }
    Resize(buf, len);
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

void Heap::TrackDown(const int node)
{
    int left = node * 2 + 1;
    int right = node * 2 + 2;

    if (left >= m_len)
    {
        return;
    }

    int sid;
    int value;

    if (m_isMaxHeapify)
    {
        value = m_data[node] < m_data[left] ? m_data[left] : m_data[node];
        if (right < m_len)
        {
            value = value < m_data[right] ? m_data[right] : value;
        }
    }
    else
    {
        value = m_data[node] > m_data[left] ? m_data[left] : m_data[node];
        if (right < m_len)
        {
            value = value > m_data[right] ? m_data[right] : value;
        }
    }

    if (value == m_data[node])
    {
        return;
    }

    if (value == m_data[left])
    {
        Swap(m_data, node, left);
        TrackDown(left);
    }

    if ((right < m_len) && (value == m_data[right]))
    {
        Swap(m_data, node, right);
        TrackDown(right);
    }
}

void Heap::TrackUp(const int node)
{
    if (0 == node)
    {
        return;
    }

    int parent = (node - 1) / 2;

    if (m_isMaxHeapify)
    {
        if (m_data[parent] < m_data[node])
        {
            Swap(m_data, parent, node);
            TrackDown(parent);
            TrackUp(parent);
        }
    }
    else
    {
        if (m_data[parent] > m_data[node])
        {
            Swap(m_data, parent, node);
            TrackDown(parent);
            TrackUp(parent);
        }
    }
}