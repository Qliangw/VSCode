#include <iostream>
#include <vector>
#include <Windows.h>
#include "array.h"

using namespace std;

int arrayAndVector()
{
    SetConsoleOutputCP(65001);
    const int n = 42;
    const int c = 1;

    //����
    int A1[n];
    vector<int> V1(n);

    //��ʼ��
    for(size_t i = 0; i < n; ++i)
        A1[i] = c;
    vector<int> V2(n,c);

    //�б��ʼ��
    vector<int> V3 = {1, 2, 3, 4, 5};
    cout << "�б��ʼ����" ;
    for(size_t i = 0; i < V3.size(); ++i)
        cout << V3[i] << " ";
    cout << endl;
    cout << endl;

    //��̬�仯
    cout << "��̬�仯��"  << endl;
    V3.push_back(6);
    cout  << "V3�Ĵ�С��" ;
    cout << V3.size() << endl;
    cout  << "V3��ĩ����";
    cout << V3.front() << " " << V3.back() << endl;

    cout  << "V3�Ĵ�С��";
    V3.pop_back();
    cout << V3.size() << endl;
    cout  << "V3��ĩ����" ;
    cout << V3.front() << " " << V3.back() << endl;
    cout << endl;

    //������
    cout << "��������" ;
    for(auto iter = V3.begin(); iter != V3.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}