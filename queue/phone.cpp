#include "myQueue.h"
#include <vector>

#include <ctime>

inline double time(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void phone()
{
    size_t L = 9;   //�ַ�������
    size_t B = 10;  //����
    //������ر𳤵��ַ��������Կ�����list<string>��������ԭʼ����
    //��Ҫ���ַ��������������ַ���ָ���������䶯����������Ч������
    vector<string> phone_number(100000,"123456789");
    //�������ܳ����ַ��������Խ����л�Ϊ����Ҳ��vector<list<string>>��
    //����Ӧ����ӳ��Ӳ�����Ϊ�����splice��������������
    vector<queue<string>> Q(B);
    //d��L - 1��0��ע���÷�
    size_t d = L;
    clock_t start = clock();
    while(d-- > 0)
    {
        //���ݵ�dλ�����ִ����ַ���
        for(const auto& x: phone_number)
            Q[x[d] - '0'].push(x);

        size_t i = 0;
        for(size_t k = 0; k < B; ++k)
            while(!Q[k].empty())
            {
                phone_number[i++] = Q[k].front();
                Q[k].pop();
            }
    }
    clock_t end = clock();
    cout << "����ʱ��(s): " << time(start, end) << endl;
}