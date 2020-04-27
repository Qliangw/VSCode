#include "myVector.h"
#include <ctime>

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void int_push_back()
{
    const size_t n = 1000000000;
    vector<int> V;
    clock_t start = clock();
    for (size_t i = 0; i < n; ++i)
        V.push_back(0);
    clock_t end = clock();
    cout << "����ʱ��(s): " << time(start, end) << endl;
}