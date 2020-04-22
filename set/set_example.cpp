#include "mySet.h"

using namespace std;

void set_example()
{
    set<int> S = {3, 2, 1, 4, 5 };
    
    //����
    S.insert(0);
    S.insert(7);

    //������ɾ��
    auto iter = S.find(0);
    if(iter != S.end())
        S.erase(iter);
    iter = S.find(5);
    if(iter != S.end())
        S.erase(iter);
    S.erase(5);

    //������λ��
    iter = S.begin();
    cout << *iter << endl;
     ++iter;//���ڵ�������˵ ++���ں���Ч�ʻ��һЩ
     cout << *iter << endl;
     --iter;
     cout << *iter << endl;

    //��������
    for(auto iter = S.cbegin(); iter != S.end(); ++iter)
        cout << *iter << " ";   
    cout << endl;

    for(auto iter = S.crbegin(); iter != S.crend(); ++iter )
        cout << *iter << " ";
    cout << endl;

    for(const auto& x: S) //ֻ�ܲ鿴
        cout << x << " ";
    cout << endl;

}