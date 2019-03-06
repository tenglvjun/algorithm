#include "heap.h"
#include <iostream>
#include "sort.h"

int main()
{
    int data[11] = {1, 34, 12, 9, 8, 11, 18, 31, 13, 25, 21};

    MergeSort(data, 11);
    for(int i = 0; i < 11; i++)
    {
        std::cout << data[i] << "   ";
    }
    std::cout << std::endl;
    
    return 0;
}