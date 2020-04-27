#include "myVector.h"
#include <ctime>

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}


template <int m>
struct xnode {
  xnode(int d)
  {
    for (int i = 0; i < m; ++i)
      data[i] = d;
  }
  int data[m];
};

void pointer_push_back()
{
    const size_t n = 100000000;
    const int m = 16;
    vector<xnode<m>*> V;
    clock_t start = clock();
    for (size_t i = 0; i < n; ++i)
    {
        xnode<m>* p = new xnode<m>(i);
        V.push_back(p);
    }
    clock_t end = clock();
    cout << "����ʱ��(s): " << time(start, end) << endl;
    for (size_t i = 0; i < V.size(); ++i)
        delete V[i];
}