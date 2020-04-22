#include "myVector.h"
#include <algorithm>
using namespace std;

void sortedVector_and_unsortedVector()
{
    int key;
    //有序向量
    vector<int> SV= {1,3,6,6,8,9};
    cout << "SV:";
    print_all(SV);
    //查找元素
    cout << "please input key:";
    cin >> key;
    auto iter = lower_bound(SV.begin(),SV.end(),key);
    cout << "iter - SV.begin = "<< iter - SV.begin() << endl;
    iter = upper_bound(SV.begin(),SV.end(),key);
    cout << "iter - SV.begin = "<< iter - SV.begin() << endl;
    //插入新元素
    key = 0;
    auto iter_SV = lower_bound(SV.begin(),SV.end(),key);
    SV.insert(iter_SV,key);
    cout << "NEW SV:";
    print_all(SV);
    
    //删除
    cout << "Delete key in the SV:";
    cin >> key;
    //如果存在则删除
    if(binary_search(SV.begin(),SV.end(),key))
    {
        iter_SV = upper_bound(SV.begin(),SV.end(),key);
        SV.erase(--iter_SV);
        cout << "NEW SV:";
        print_all(SV);
    }
    else
    {
        cout << "key does't exist " << endl;
    }
    //查找重复key所在的区间range,区间为[range.first range.second]
    auto range = equal_range(SV.begin(),SV.end(),key);
    //删除整个range区间的元素   
    SV.erase(range.first, range.second);
    //打印
    print_all(SV);
    cout << endl ;

    //无序向量
    vector<int> USV = {9,6,1,3,8,6};
    cout << "USV:";
    print_all(USV);
    //插入新元素
    key = 0;
    USV.push_back(key);
    print_all(USV);

    cout << "Delete key in the USV:";
    cin >> key;
    // auto iter_USV = find(USV.begin(),USV.end(),key);
    // *iter_SV = USV.back();
    auto riter = find(USV.rbegin(),USV.rend(),key);
    if(riter != USV.rend())
    {
        *riter = USV.back();
        USV.pop_back();
    }
    
    print_all(USV);
}