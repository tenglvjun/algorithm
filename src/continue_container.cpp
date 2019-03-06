#include "continue_container.h"
#include "macro.h"
#include <memory.h>
#include <assert.h>
#include <iostream>

#if !defined(DEFAULT_CONTINUE_CONTAINER_CAP)
#define DEFAULT_CONTINUE_CONTAINER_CAP 10
#endif // DEFAULT_CONTINUE_CONTAINER_CAP

ContinueContainer::ContinueContainer()
    : m_data(nullptr), m_len(0), m_cap(DEFAULT_CONTINUE_CONTAINER_CAP)
{
    Alloc();
}

ContinueContainer::ContinueContainer(const int *data, const int len)
    : m_data(nullptr), m_len(0), m_cap(DEFAULT_CONTINUE_CONTAINER_CAP)
{
    Resize(data, len);
}

ContinueContainer::ContinueContainer(const ContinueContainer &c)
    : m_data(nullptr), m_len(0), m_cap(DEFAULT_CONTINUE_CONTAINER_CAP)
{
    Resize(c.m_data, c.m_len);
}

ContinueContainer::~ContinueContainer()
{
    Dealloc();
}

ContinueContainer &ContinueContainer::operator=(const ContinueContainer &c)
{
    if (this == &c)
    {
        return *this;
    }

    Resize(c.m_data, c.m_len);

    return *this;
}

int &ContinueContainer::operator[](const int idx)
{
    assert(idx < m_len);

    return m_data[idx];
}

void ContinueContainer::Resize(const int cap)
{
    if (cap == m_cap)
    {
        return;
    }

    m_cap = cap;
    m_len = m_len > m_cap ? m_cap : m_len;

    int *buf = new int[m_cap];
    memset(buf, 0, sizeof(int) * m_cap);
    memcpy(buf, m_data, sizeof(int) * m_len);

    SAFE_DELETE_ARRAY(m_data);
    m_data = buf;
}

void ContinueContainer::Resize(const int *data, const int len)
{
    m_cap = (m_cap <= len) ? (len * 2) : m_cap;
    m_len = len;
    Alloc();

    memcpy(m_data, data, sizeof(int) * m_len);
}

void ContinueContainer::PushBack(const int v)
{
    if (m_len == m_cap)
    {
        Resize(m_cap * 2);
    }

    m_data[++m_len] = v;
}

void ContinueContainer::Erase(const int idx)
{
    assert(m_len > idx);
    if (idx == (m_len - 1))
    {
        m_len--;
        return;
    }

    memcpy(m_data + idx, m_data + idx + 1, sizeof(int) * (m_len - idx - 1));
    m_len--;
}

void ContinueContainer::Output()
{
    for (int i = 0; i < m_len; i++)
    {
        std::cout << m_data[i] << "  ";
    }
    std::cout << std::endl;
}

void ContinueContainer::Insert(const int v, const int idx)
{
    assert(m_len > idx);
    if (m_len == m_cap)
    {
        Resize(m_cap * 2);
    }

    memcpy(m_data + idx + 1, m_data + idx, sizeof(int) * (m_len - idx));
    m_data[idx] = v;
    m_len++;
}

void ContinueContainer::Swap(const int i, const int j)
{
    assert((m_len > i) && (m_len > j));

    int tmp = m_data[i];
    m_data[i] = m_data[j];
    m_data[j] = tmp;
}

void ContinueContainer::Alloc()
{
    SAFE_DELETE_ARRAY(m_data);
    m_data = new int[m_cap];
    memset(m_data, 0, sizeof(int) * m_cap);
}

void ContinueContainer::Dealloc()
{
    SAFE_DELETE_ARRAY(m_data);
    m_len = m_cap = 0;
}