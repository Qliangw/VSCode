#include "mySet.h"

using namespace std;

void set_example()
{
    set<int> S = {3, 2, 1, 4, 5 };
    
    //插入
    S.insert(0);
    S.insert(7);

    //查找与删除
    auto iter = S.find(0);
    if(iter != S.end())
        S.erase(iter);
    iter = S.find(5);
    if(iter != S.end())
        S.erase(iter);
    S.erase(5);

    //迭代器位置
    iter = S.begin();
    cout << *iter << endl;
     ++iter;//对于迭代器来说 ++放在后面效率会低一些
     cout << *iter << endl;
     --iter;
     cout << *iter << endl;

    //遍历集合
    for(auto iter = S.cbegin(); iter != S.end(); ++iter)
        cout << *iter << " ";   
    cout << endl;

    for(auto iter = S.crbegin(); iter != S.crend(); ++iter )
        cout << *iter << " ";
    cout << endl;

    for(const auto& x: S) //只能查看
        cout << x << " ";
    cout << endl;

}