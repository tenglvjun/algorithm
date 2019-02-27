#include "search.h"
#include <iostream>

int main()
{
    int pos;
    double oneD[11] = {1, 34, 12, 45, 8, 11, 18, 45, 32, 21, 21};

    std::cout << FindPeakOneD(oneD, 0, 10, pos) << std::endl;
    std::cout << pos << std::endl;

    double **towD = new double *[4];
    for (size_t i = 0; i < 4; i++)
    {
        towD[i] = new double[4];
    }

    double tmp[] = {1, 34, 12, 87, 8, 11, 18, 12, 32, 21, 21, 6, 24, 8, 2, 77};
    for(int i = 0; i < 16; i++)
    {
        int row = i / 4;
        int col = i % 4;

        towD[row][col] = tmp[i];
    }
    
    std::cout << FindPeakTwoD(towD, 4, 0, 3) << std::endl;

    return 0;
}