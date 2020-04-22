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

// ���ñ�����Ҫ��V�ĳ���������2, �����ѳ�ʼ��. ����Ҫ��n >= 1.
size_t memoized_Collatz(vector<size_t>& V, size_t n)
{
  // ���n��������V���±귶Χ֮��, ��ת��������Χ֮�ڲ�����ƫ��D.
  size_t d = 0;
  while (n >= V.size()) // ע��˴����V.size() <= 1������.
  {
    n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
    ++d;
  }
  // ��V[n]���и�ֵ, ע��˴�n������V���±귶Χ֮��, ֱ�ӵݹ��1��ֵ����.
  if (V[n] == 0)
    V[n] = memoized_Collatz(V, (n % 2 == 0) ? n / 2 : 3 * n + 1) + 1;
  // ����ֵ��ԭ�е�n��Ӧ�����г���, Ӧ����ƫ����D.
  return V[n] + d;
}

void test_memoized_Collatz()
{
    size_t n; 
    const size_t m = 10000;
    vector<size_t> V(m, 0);
    V[1] = 1;
    // ���Ե����ͱ���¼�������Ƿ�һ��, ���Է�ΧΪ[1, max].
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