#include "myQueue.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void buffer()
{
    vector<int> buffer;
    size_t C = 10;      //����ΪC
    size_t N = C + 1;   //��ʵbuffer����ΪN
    buffer.resize(N);
    // front��rear�ĳ�ֵ��ѡbuffer�е�һ��λ�ã����ﶼȡΪN/2
    size_t front = N / 2;
    size_t rear  = N / 2;
    int x = 0;
    //��buffer��������������0��1,2��...��C-1
    while(rear + 1 < N? front != rear + 1: front != 0)
    {
        buffer[rear] = x++;
        //����Ĳ�����rear = (rear + 1) % N����
        if(rear < C)
            ++rear;
        else
            rear = 0;
    }
    //��buffer���գ����������Ԫ�ز�����
    while(front != rear)
    {
        cout << buffer[front] << " ";
        //���������front = (front + 1) % N����
        if(front < C)
            ++ front;
        else
            front = 0;
    }
    cout << endl;


    cout << "ֱ��ʹ�ö���" << endl;
    queue<int> Q;
    for(x = 0; Q.size() != C; x++)
        Q.push(x);
    while(!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
}