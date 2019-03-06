#include "tools.h"
#include <assert.h>

void Swap(int *data, const int i, const int j)
{
    assert(data);

    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}