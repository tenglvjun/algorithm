#if !defined(__SEARCH_HEAD_FILE__)
#define __SEARCH_HEAD_FILE__

int FindMaximum(const int *data, const int len, int &pos);
int FindPeakOneD(const int *data, const int begin, const int end, int &pos);
int FindPeakTwoD(int **data, const int cols, const int s_row, const int e_row);

#endif // __SEARCH_HEAD_FILE__
