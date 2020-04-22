#include "myVector.h"
#include <algorithm>
using namespace std;

void sortedVector_and_unsortedVector()
{
    int key;
    //��������
    vector<int> SV= {1,3,6,6,8,9};
    cout << "SV:";
    print_all(SV);
    //����Ԫ��
    cout << "please input key:";
    cin >> key;
    auto iter = lower_bound(SV.begin(),SV.end(),key);
    cout << "iter - SV.begin = "<< iter - SV.begin() << endl;
    iter = upper_bound(SV.begin(),SV.end(),key);
    cout << "iter - SV.begin = "<< iter - SV.begin() << endl;
    //������Ԫ��
    key = 0;
    auto iter_SV = lower_bound(SV.begin(),SV.end(),key);
    SV.insert(iter_SV,key);
    cout << "NEW SV:";
    print_all(SV);
    
    //ɾ��
    cout << "Delete key in the SV:";
    cin >> key;
    //���������ɾ��
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
    //�����ظ�key���ڵ�����range,����Ϊ[range.first range.second]
    auto range = equal_range(SV.begin(),SV.end(),key);
    //ɾ������range�����Ԫ��   
    SV.erase(range.first, range.second);
    //��ӡ
    print_all(SV);
    cout << endl ;

    //��������
    vector<int> USV = {9,6,1,3,8,6};
    cout << "USV:";
    print_all(USV);
    //������Ԫ��
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