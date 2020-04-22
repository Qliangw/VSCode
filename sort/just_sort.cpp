#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "sort.h"

using namespace std;

void alg_sort()
{
    const int n = 5;
    int arr[n] = {2,5,3,1,4};

    // ��С��������.
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i)
        cout << arr[i] <<" ";
    cout << endl << endl;

    // ʹ�ú�������greater<int>()���дӴ�С����.
    // �еı�����������Ҫfunctionalͷ�ļ�.
    sort(arr, arr + n, greater<int>());
        for(int i = 0; i < n; ++i)
        cout << arr[i] <<" ";
    cout << endl;

    // ���ַ�������.
    string B[n] = {"www", "algorithm", "racer", "text", "wait"};
    sort(B, B + n);
    for (int i = 0; i < n; ++i)
        cout << B[i] << endl;
    cout << endl;

    sort(B, B + n, greater<string>());
    for (int i = 0; i < n; ++i)
        cout << B[i] << endl;

    // ����������.
    vector<string> V = {"www", "algorithm", "racer", "text", "wait"};
    // ��С��������.
    sort(V.begin(), V.end());
    // ʹ�ú�������greater<int>()���дӴ�С����.
    sort(V.begin(), V.end(), greater<string>());
    // ʹ�õ�������ӡV������Ԫ��.
    for (auto iter = V.begin(); iter != V.end(); ++iter)
        cout << *iter << endl;
    // ʹ��������������дӴ�С����.
    sort(V.rbegin(), V.rend());
    // ʹ�û��ڷ�Χ��forѭ����ӡV������Ԫ��.
    for (const string& x : V)
        cout << x << endl;


}