#include <iostream>
#include <set>
#include <vector>
#include "mySet.h"

using namespace std;

//寻找第k个元素
void order_statistics_set()
{
    set<int> S = {3, 2, 1, 4, 5};

    int k;
    cout << "input k:";
    cin >> k;
    // 第一种方法:
    if(k <= 0 || k > S.size())
        cout << "err" << endl;
    else
    {
        auto iter = S.begin();
        
        for(int i = 0; i < k-1; ++i)
            ++iter;
        cout << *iter << endl;
    }
    

    //第二种方法
    
}