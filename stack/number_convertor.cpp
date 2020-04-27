#include "myStack.h"
#include <string>

using namespace std;

void convertor_with_stack(int number, size_t b)
{
    string d2c = "0123456789ABCDEF";
    string result;  //ʵ������ջ�����������ַ��������㣻
    if(number < 0)
    {
        result += "-";
        number = -number;
    }

    stack<char> S;
    do{
        S.push(d2c[number % b]);
        number /= b;
    }while(number != 0);
    
    while(!S.empty())
    {
        result += S.top();
        S.pop();
    }

    cout << result << endl;
}

void convertor_with_string(int number, size_t b)
{
    string d2c = "0123456789ABCDEF";
    string result;
    size_t start = 0;
    if(number < 0)
    {
        result += "-";
        number = -number;
        start = 1;
    }
    
    do{
        result.push_back(d2c[number % b]);
        number /= b;
    }while(number != 0);

    //�����������ַ���������ֱ������[start, result.size()]λ��
    //��ȻҲ��ǰ���ȵ�������'-'�ַ������ý�����ƴ��
    for(size_t i = start; i < (result.size() + start) / 2; ++i)
    {
        swap(result[i], result[result.size() - 1 - i + start]);
    }
    cout << result << endl;
}

void number_convertor()
{
    cout << "��������Ҫת��������";
    int number;
    cin >> number;
    size_t b;
    cout << "��������ת���Ľ��ƣ�2-16֮�䣩��";
    cin >> b;
    if(b >= 2 && b <= 16)
    {
        convertor_with_stack(number,b);
        convertor_with_string(number,b);
    }
    else
    {
        cout << "x������������" << endl;
    }
    
}