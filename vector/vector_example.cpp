#include "myVector.h"

void vector_example()
{
    //����һ����ʼ����Ϊ10������A������λ����Ϊ10
    vector<int> A(10);
    //�±�i��0��A.size() - 1��A��ÿ��Ԫ�ظ�ֵi.
    // Ϊ����������ʹ��size_t��, ʵ����iӦ����vector<int>::size_type��.
    // �������±��÷���������ͬ, ��Ҫע��Ӧ��֤������ʵ��Ԫ�ظ�������size().
    for(size_t i = 0; i < A.size(); ++i)
        A[i] = static_cast<int>(i);
    // ʹ�õ�����iter������A��ÿ��Ԫ�ظ�ֵ1.
    // �������ɴ������Ŀ�ʼ������, ����ָ��.
    // Ҫע��begin()��end()���÷�: begin()λ������Ԫ��, ��end()λ��û��Ԫ�ش���.
    // iterΪvector<int>::iterator��, ����auto�ؼ�����ϸ�ֵ����Զ���ȡ������.
    // for (auto iter = A.begin(); iter != A.end(); ++iter)
    //     *iter = 1;

    // ����һ������Ϊ5������B, ��ʼԪ��ȫΪ3.
    vector<int> B(5, 3);
    // ������Bĩβ����100��2.
    B.resize(B.size() + 100, 2);
    // ������B��β������4.
    B.push_back(4);
    // ����������һ���÷�
    auto iter = B.begin();
    for (size_t i = 0; i < B.size(); ++i)
        *(iter + i) *= 2;
    // ������B��Ϊ��, ����������β��Ԫ�ز�ɾ��֮.
    while(!B.empty())
    {
        cout << B.back() << " "; // �������B��ĩβԪ��
        B.pop_back();             // ɾ������B��ĩβԪ��
    }
    cout << endl;
    // ����δ֪���ȵ���Ȼ����������, �Ը�����Ϊ������ֹ. C��ʼΪ������.
    vector<int> C;
    int data;
    cout << "������Ȼ��, �Ը�����Ϊ������ֹ:"<< endl;
    // ����push_back�������ٶȷǳ���.
    for (cin >> data; data >= 0; cin >> data)
        C.push_back(data);
    for (const auto& x : C)
        cout << x << " ";
    cout << endl;

    // �����ĳ�ʼ���б�.
    vector<int> D = {4, 2, 1, 5, 3};
    print_all(D);
}