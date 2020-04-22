#include "myVector.h"
#include <algorithm>
using namespace std;

void sortedVector_and_unsortedVector()
{
    int key;
    //有序向量
    vector<int> SV= {1,3,6,6,8,9};
    //插入
    key = 0;
    auto iter_SV = lower_bound(SV.begin(),SV.end(),key);
    SV.insert(iter_SV,key);

    //删除
    key = 6;
    iter_SV = upper_bound(SV.begin(),SV.end(),key);
    --iter_SV;
    SV.erase(iter_SV);

    //无序向量
    vector<int> USV = {9,6,1,3,8,6};
    key = 0;
    USV.push_back(key);
    key = 6;
    auto iter_USV = find(USV.begin(),USV.end(),key);
    *iter_SV = USV.back();
    USV.pop_back();
}