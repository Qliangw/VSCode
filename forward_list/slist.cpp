#include "myForwardList.h"

using namespace std;

struct snode{
    int data;
    snode* next;
};

void slist()
{
    snode sentinal;
    snode* header = &sentinal;
    snode A = {1, NULL};
    snode B = {2, NULL};
    snode C = {3, NULL};
    snode* p;
    p = header;
    p->next = &A;
    p = p->next;
    p->next = &B;
    p = p->next;
    p->next = &C;
    for(p = header->next; p != NULL; p = p->next)
        cout << p->data << endl;

    //�Ƚ��ڵ�A֮��Ľڵ�Bɾ��
    p = &A;
    snode* q = p->next;
    p->next = q->next;
    //�ٽ���ɾ���Ľڵ�B���뵽�ڵ�C֮��
    p = p->next;
    q->next = p->next;
    p->next = q;
    for (p = header->next; p!= NULL; p = p->next)
    {
        cout << p->data << endl;
    }
    vector<snode> V = {{}, {1, NULL}, {2, NULL}, {3, NULL}};
    header = p = &V[0];
    for (size_t i = 1; i < V.size(); ++i)
    {
        p->next = &V[i];
        p = p->next;
    }
    for (p = header->next; p != NULL; p = p->next)
        cout << p->data << endl;
    
}