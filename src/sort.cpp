#include "sort.h"
#include <assert.h>
#include "tools.h"
#include <memory.h>
#include "macro.h"
#include <iostream>

void InsertSort(int *buf, int len, bool maximum /* = true */)
{
    assert(buf);

    if (len <= 1)
    {
        return;
    }

    int i, j, k;
    for (i = 1; i < len; i++)
    {
        j = i;
        k = j - 1;
        while (k >= 0)
        {
            if (maximum)
            {
                if (buf[j] > buf[k])
                {
                    Swap(buf, j, k);
                    j = k;
                    k = j - 1;
                }
                else
                {
                    k--;
                }
            }
            else
            {
                if (buf[j] < buf[k])
                {
                    Swap(buf, j, k);
                    j = k;
                    k = j - 1;
                }
                else
                {
                    k--;
                }
            }
        }
    }
}

void MergeSort(int *buf, int len, bool maximum /* = true */)
{
    int middle = len / 2;

    if (middle == 0)
    {
        return;
    }

    int l_len = middle;
    int r_len = len - middle;

    int *left = new int[l_len];
    int *right = new int[r_len];

    memcpy(left, buf, sizeof(int) * l_len);
    memcpy(right, (buf + l_len), sizeof(int) * r_len);

    MergeSort(left, l_len, maximum);
    MergeSort(right, r_len, maximum);

    if (l_len == 0)
    {
        memcpy(buf, right, sizeof(int) * r_len);
        return;
    }

    if (r_len == 0)
    {
        memcpy(buf, left, sizeof(int) * l_len);
        return;
    }

    int i, j, k;
    i = j = 0;
    k = i + j;

    while (k < len)
    {
        if (i == l_len)
        {
            memcpy(buf + k, right + j, sizeof(int) * (r_len - j));
            break;
        }

        if (j == r_len)
        {
            memcpy(buf + k, left + i, sizeof(int) * (l_len - i));
            break;
        }

        if (left[i] < right[j])
        {
            buf[k++] = right[j];
            j++;
        }
        else
        {
            buf[k++] = left[i];
            i++;
        }
    }

    SAFE_DELETE_ARRAY(left);
    SAFE_DELETE_ARRAY(right);

    return;
}