#include "myVector.h"

void doubling()
{
    const size_t n = 40;
    // size()���ص�ǰԪ�ظ���, capacity()���ص�ǰ����.

    vector<int> A;
    for (size_t i = 0; i < n; ++i)
    {
        cout << A.size() << " " << A.capacity() << endl;
        A.push_back(0); 
    }
    cout << A.size() << " " << A.capacity() << endl;

    vector<int> B;
    // ��ǰԤ������n.
    B.reserve(n);
    for (size_t i = 0; i < n; ++i)
    {
        cout << B.size() << " " << B.capacity() << endl;
        B.push_back(0);
    }
    cout << B.size() << " " << B.capacity() << endl;    
}