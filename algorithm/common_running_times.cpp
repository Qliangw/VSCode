#include <ctime>      // ʱ��.
#include <algorithm>  // �㷨��.
#include "myAlgorithm.h"


inline double time(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void common_running_times()
{
    //��ʱ����
    clock_t start , end;
    const size_t N = 10000000;

    // ռ�õĴ洢���ܴ�.
    vector<size_t> v(N);

    //����ʱ��
    start = clock();
    for (size_t i = 0; i < v.size(); ++i)
        v[i] = v.size() - i;
    end = clock();
    cout << "����ʱ��(s):" << time(start,end)<<endl;

    // �߶�ʱ��
    start = clock();
    sort(v.begin(), v.end());
    end = clock();
    cout << "����ʱ��(s): " << time(start, end) << endl;

    // ����ʱ��
    start = clock();
    binary_search(v.begin(), v.end(), 1);
    end = clock();
    cout << "����ʱ��(s): " << time(start, end) << endl;

    // ƽ��ʱ��, �޷�ʹ��N�����ģ��.
    size_t M = 100000;
    start = clock();
    for (size_t i = 0; i < M; ++i)
        for (size_t j = 0; j < M; ++j)
            v[i] *= j;
    end = clock();
    cout << "����ʱ��(s): " << time(start, end) << endl;
    // �����N�����ģ��, ��Ҫ����ʱ��?
    cout << "��������ʱ��(s): " << time(start, end) * (N / M) * (N / M) << endl;

}
