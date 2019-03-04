#include "heap.h"

int main()
{
    double data[11] = {1, 34, 12, 48, 8, 11, 18, 31, 32, 25, 21};

    Heap heap(data, 11);
    heap.Output();

    return 0;
}