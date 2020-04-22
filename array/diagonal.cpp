#include <iostream>
#include "array.h"
using namespace std;

int diagonal()
{
  const int n = 10;
  int x = 1;
  int y = 0;
  int M[n][n];

  // 方法1:
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i == j)
        M[i][j] = x;
      else
        M[i][j] = y;

  // // 方法2:
  // for (int i = 0; i < n; ++i)
  //   for (int j = 0; j < n; ++j)
  //     M[i][j] = y;
  // for (int i = 0; i < n; ++i)
  //   M[i][i] = x;

  // 方法3:
  // for (int i = 0; i < n; ++i)
  // {
  //   for (int j = 0; j < i; ++j)
  //     M[i][j] = y;
  //   M[i][i] = x;
  //   for (int j = i + 1; j < n; ++j)
  //     M[i][j] = y;
  // }

  // 在屏幕上输出.
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      cout << M[i][j] << " ";
    cout << endl;
  }

  system("pause");
  return 0;
}