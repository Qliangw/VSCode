#include "mySet.h"
#include <string>
#include <vector>

using namespace std;

void descriptiong()
{
    //差集
    set<int> A = {3,2,1,4,7,9,11};
    set<int> B = {6,2,9};
    cout << "A:";
    print_all(A);
    cout << "B:";
    print_all(B);

    vector<int> C;
    for(auto iter = A.begin(); iter != A.end(); ++iter)
    {
        if(B.find(*iter) == B.end())
        {
            C.push_back(*iter);
        }
    }
    cout << "C:";
    print_all(C);

    //转存
    set<string> D = {"Englsih","Ability","Alogroithm","Faith","Data"};
    cout << "D:";
    print_all(D);
    set<string> E;
    while(!D.empty())
    {
        if((*D.begin()).size() % 2 == 0)
            E.insert(*D.begin());
        D.erase(*D.begin());
    }
    cout << "E:";
    print_all(E);

    //动态变化
    set<int> F = {3,5,1,7,2,8,0};
    cout << "F:";
    print_all(F);
    cout << endl;
    while(F.size() > 1)
    {
        int first = *F.begin();
        F.erase(F.begin());
        print_all(F);
        int second = *F.begin();
        F.erase(F.begin());
        print_all(F);
        F.insert(first + second);
        cout << "first=" << first << " ";
        cout << "second=" << second << endl;
    }
    
    if(F.size() > 0)
        cout << *F.begin() << endl;
}