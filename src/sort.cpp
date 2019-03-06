#include "sort.h"
#include <assert.h>
#include "tools.h"

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
}