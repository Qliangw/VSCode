#include "myStack.h"
#include <string>

using namespace std;

bool validator(const string& brackets)
{
    stack<char> S;
    for(size_t i = 0; i < brackets.size(); ++i)
    {
        switch(brackets[i])
        {
            case '(':
                S.push(brackets[i]);
                break;
            case ')':
                if(S.empty() || S.top() != '(' )
                    return false;
                S.pop();
                break;
            case '[':
                S.push(brackets[i]);
                break;
            case ']':
                if(S.empty() || S.top() != '[' )
                    return false;
                S.pop();
                break;
            case '{':
                S.push(brackets[i]);
                break;
            case '}':
                if(S.empty() || S.top() != '{' )
                    return false;
                S.pop();
                break;
            default:
                return false;
        }
    }
    return S.empty();
}

void brackets_validator()
{
    string brackets;
    cin >> brackets;
    cout << (validator(brackets) ? "Æ¥Åä" : "²»Æ¥Åä»ò´æÔÚ·ÇÀ¨ºÅ×Ö·û") << endl;
}