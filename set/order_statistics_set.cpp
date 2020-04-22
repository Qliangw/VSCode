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
    // 第一种方法: 优先选择
    if(k <= 0 || k > S.size())
        cout << "err" << endl;
    else
    {
        auto iter = S.begin();
        
        for(int i = 0; i < k-1; ++i)
            ++iter;
        cout << *iter << endl;
    }
    

    //第二种方法 较慢
    vector<int> V;
    //预留k-1个元素空间
    V.reserve(k-1);
    //删除S中的前k-1个元素并暂存到V中
    for(int i = 0; i < k-1; ++i)
    {
        V.push_back(*S.begin());
        S.erase(S.begin());
    }
    cout << *S.begin() << endl;
    //将前k-1个元素放回S中，也可以对V使用基于范围的for循环
    S.insert(V.begin(), V.end());
    for(size_t i = 0; i < V.size(); ++i)
        S.insert(V[i]);
}