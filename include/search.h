#if !defined(__SEARCH_HEAD_FILE__)
#define __SEARCH_HEAD_FILE__

double FindMaximum(const double *data, const int len, int &pos);
double FindPeakOneD(const double *data, const int begin, const int end, int &pos);
double FindPeakTwoD(double **data, const int cols, const int s_row, const int e_row);

#endif // __SEARCH_HEAD_FILE__
