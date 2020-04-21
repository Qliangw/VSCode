#include "mySet.h"
#include <iostream>
#include <set>
using namespace std;

void set_example()
{
    set<int> S = {3, 2, 1, 4, 5 };

    S.insert(1);
    S.insert(7);

    auto iter = S.find(0);
    iter = S.find(5);

    if(iter != S.end())
        S.erase(iter);

    iter = S.begin();
    ++iter;//对于迭代器来说 ++放在后面效率会低一些
    --iter;

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