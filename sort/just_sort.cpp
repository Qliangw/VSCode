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

    // 从小到大排序.
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i)
        cout << arr[i] <<" ";
    cout << endl << endl;

    // 使用函数对象greater<int>()进行从大到小排序.
    // 有的编译器可能需要functional头文件.
    sort(arr, arr + n, greater<int>());
        for(int i = 0; i < n; ++i)
        cout << arr[i] <<" ";
    cout << endl;

    // 对字符串排序.
    string B[n] = {"www", "algorithm", "racer", "text", "wait"};
    sort(B, B + n);
    for (int i = 0; i < n; ++i)
        cout << B[i] << endl;
    cout << endl;

    sort(B, B + n, greater<string>());
    for (int i = 0; i < n; ++i)
        cout << B[i] << endl;

    // 对向量排序.
    vector<string> V = {"www", "algorithm", "racer", "text", "wait"};
    // 从小到大排序.
    sort(V.begin(), V.end());
    // 使用函数对象greater<int>()进行从大到小排序.
    sort(V.begin(), V.end(), greater<string>());
    // 使用迭代器打印V中所有元素.
    for (auto iter = V.begin(); iter != V.end(); ++iter)
        cout << *iter << endl;
    // 使用逆向迭代器进行从大到小排序.
    sort(V.rbegin(), V.rend());
    // 使用基于范围的for循环打印V中所有元素.
    for (const string& x : V)
        cout << x << endl;


}