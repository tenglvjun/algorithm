#include "heap.h"
#include <iostream>

int main()
{
    int data[11] = {1, 34, 12, 9, 8, 11, 18, 31, 13, 25, 21};

    Heap heap(data, 11);
    heap.Output();
    heap.PushBack(35);
    heap.Output();
    std::cout << heap.PopFront() << std::endl;
    heap.Output();
    heap.Sort();
    heap.Output();

    return 0;
}