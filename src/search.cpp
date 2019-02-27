#include "search.h"

double FindMaximum(const double *data, const int len, int &pos)
{
    pos = 0;
    double max = data[0];

    for (int i = 0; i < len; i++)
    {
        if (max < data[i])
        {
            max = data[i];
            pos = i;
        }
    }

    return max;
}

double FindPeakOneD(const double *data, const int begin, const int end, int &pos)
{
    if (begin == end)
    {
        pos = begin;
        return data[begin];
    }

    int middle = (end + begin) / 2;
    int left = middle - 1;
    int right = middle + 1;

    if ((data[middle] >= data[left]) && (data[middle] >= data[right]))
    {
        return data[middle];
    }

    if (data[middle] < data[left])
    {
        return FindPeakOneD(data, begin, left, pos);
    }

    return FindPeakOneD(data, right, end, pos);
}

double FindPeakTwoD(double **data, const int cols, const int s_row, const int e_row)
{
    int c;
    if (s_row == e_row)
    {
        return FindMaximum(data[0], cols, c);
    }
    
    int middle = (s_row + e_row) / 2;
    double max = FindMaximum(data[middle], cols, c);

    if ((max >= data[middle-1][c]) && (max >= data[middle+1][c]))
    {
        return max;
    }

    if (max < data[middle-1][c])
    {
        return FindPeakTwoD(data, cols, s_row, middle-1);
    }

    return FindPeakTwoD(data, cols, middle+1, e_row);
}