#include <vector>
#include "mySet.h"

using namespace std;

//Ѱ�ҵ�k��Ԫ��
void order_statistics_set()
{
    set<int> S = {3, 2, 1, 4, 5};

    int k;
    cout << "input k:";
    cin >> k;
    // ��һ�ַ���: ����ѡ��
    if(k <= 0 || k > S.size())
        cout << "err" << endl;
    else
    {
        auto iter = S.begin();
        
        for(int i = 0; i < k-1; ++i)
            ++iter;
        cout << *iter << endl;
    }
    

    //�ڶ��ַ��� ����
    vector<int> V;
    //Ԥ��k-1��Ԫ�ؿռ�
    V.reserve(k-1);
    //ɾ��S�е�ǰk-1��Ԫ�ز��ݴ浽V��
    for(int i = 0; i < k-1; ++i)
    {
        V.push_back(*S.begin());
        S.erase(S.begin());
    }
    cout << *S.begin() << endl;
    //��ǰk-1��Ԫ�طŻ�S�У�Ҳ���Զ�Vʹ�û��ڷ�Χ��forѭ��
    S.insert(V.begin(), V.end());
    for(size_t i = 0; i < V.size(); ++i)
        S.insert(V[i]);
}