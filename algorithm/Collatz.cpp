#include "myAlgorithm.h"

using namespace std;

size_t itertive_Collatz(size_t n)
{
    if(n < 1)
        return 0;
    size_t len = 1;
    while(n != 1)
    {
        // if(n % 2 == 0)
        //     n = n /2;
        // else  
        //     n = 3*n + 1;
        n = (n % 2 == 0) ? n/2 : 3*n+1;
        ++ len;
    }
    return len;
}

// 调用本函数要求V的长度至少是2, 并且已初始化. 另外要求n >= 1.
size_t memoized_Collatz(vector<size_t>& V, size_t n)
{
  // 如果n不在向量V的下标范围之内, 先转换到合理范围之内并计算偏移D.
  size_t d = 0;
  while (n >= V.size()) // 注意此处如果V.size() <= 1则会出错.
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++d;
  }
  // 对V[n]进行赋值, 注意此处n在向量V的下标范围之内, 直接递归加1赋值即可.
  if (V[n] == 0)
    V[n] = memoized_Collatz(V, (n % 2 == 0) ? n / 2 : 3 * n + 1) + 1;
  // 返回值是原有的n对应的序列长度, 应加上偏移量D.
  return V[n] + d;
}

void test_memoized_Collatz()
{
    size_t n; 
    const size_t m = 10000;
    vector<size_t> V(m, 0);
    V[1] = 1;
    // 测试迭代和备忘录计算结果是否一致, 测试范围为[1, max].
    size_t max = 100000;

    while(1)
    {
        
        cout << "please in nums:" << endl ;  
        cin >> n;
        if(n<1)
            cout << 0 << endl;
        else if(n > max)
            cout << "err" << endl;
        else
            cout << memoized_Collatz(V,n) << endl;
    }
}