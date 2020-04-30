#include "myStack.h"
#include <string>

using namespace std;

//4��״̬�����Լ���Ӧ��ʾ����ע��ʹ��textʱ�±�Ҫ����ƫ��s
const int s =4;
enum status{
    not_matched = -4, 
    matched     = -3, 
    illegal     = -2, 
    in          = -1,
};

const string text[s] = {
    "��ƥ��",
    "ƥ��",
    "���ڷǷ��ַ�",
    "",
};

int generalized_validator(const string& brackets, int value[])
{
    stack<char> S;
    for(auto x : brackets)
        if (value[(int)x] == illegal)           //�Ƿ�����ֱ���˳�
            return illegal;
        else if (value[(int)x] == in)           //������Ӧ�ý�ջ
            S.push(x);
        else if(S.empty() || S.top() != value[(int)x]) //�޷���ջ
            return not_matched;
        else 
            S.pop();
    return S.empty() ? matched : not_matched;
}

void generalized_validator_test()
{
    const int n = 256;
    int value[n];
    for (size_t i = 0; i < n; ++i)
        value[i] = illegal;
    value[(int)'L'] = in;
    value[(int)'R'] = (int)'L';
    value[(int)'<'] = in;
    value[(int)'>'] = (int)'<';
    value[(int)'['] = in;
    value[(int)']'] = (int)'[';
    string brackets;
    cin >> brackets;
    cout << text[s + generalized_validator(brackets,value)] << endl;
}