/*********************************************************
* ǰ������������ -> ������ -> ������
* ��������������� -> ����� -> ������
* ��������������� -> ������ -> �����
* ��α�����
*********************************************************/

#include "mySet.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct tnode {
    T data;
    tnode<T>* left;
    tnode<T>* right;
    tnode<T>* parent;
};

template <typename iterator>
void pre_order(iterator p)      //ǰ�����
{
    if (p != NULL)
    {
        cout << p->data << ' ';
        pre_order(p->left);
        pre_order(p->right);
    }
}

template <typename iterator> 
void in_order(iterator p)       //������� ���������˳���ں����ϵ�ͶӰ
{
    if(p != NULL)
    {
        in_order(p->left);
        cout << p->data << ' ';
        in_order(p->right);
    }
}

template <typename iterator>  
void post_order(iterator p)     //�������
{
    if(p != NULL)
    {
        post_order(p->left);
        post_order(p->right);
        cout << p->data << ' ';
    }
}

template <typename iterator>  
void level_order(iterator p)
{
    queue<iterator> Q;
    if(p != NULL)
        Q.push(p);
    while(!Q.empty())
    {
        iterator f = Q.front();
        cout << f->data << ' ';
        if(f->left != NULL)
            Q.push(f->left);
        if(f->right != NULL)
            Q.push(f->right);
        Q.pop();
    }
}

double alpha;

template <typename iterator>  
iterator tree_generation(iterator start, size_t n)
{
    if(n < 1)
        return NULL;
    size_t c = (n - 1) * alpha;
    iterator root = start + c;
    iterator left_subtree = tree_generation(start, c);
    iterator right_subtree = tree_generation(start + c + 1, n - 1 -c);
    root->left = left_subtree;
    root->right = right_subtree;
    if(left_subtree != NULL)
        left_subtree->parent = root;
    if(right_subtree != NULL)
        right_subtree->parent = root;
    return root;
}

template <typename iterator>  
iterator left_most(iterator p)          //��СԪ
{
    while(p->left != NULL)
        p = p->left;
    return p;
}

template <typename iterator>
iterator right_most(iterator p)         //���Ԫ
{
    while(p->right != NULL)
        p = p->right;
    return p;
}

template <typename iterator>
iterator next_position(iterator p)      //��һ��Ԫ��
{
    if(p->right != NULL)
        return left_most(p->right);
    iterator last = p;
    while(p != NULL)
    {
        if(last == p->left)
            return p;
        last = p;
        p = p->parent;
    }
    return p;
}

template <typename iterator>  
iterator prev_position(iterator p)      
{
    if(p->left != NULL)
        return right_most(p->left);
    iterator last = p;
    while(p != NULL)
    {
        if(last == p->right)
            return p;
        last = p;
        p = p->parent;
    }
    return p;
}

int binary_tree()
{
    size_t n;
    cin >> n;
    if(n < 1)
        return 0;
    
    vector<tnode<size_t>> tree(n);
    for (size_t i = 0; i < tree.size(); ++i)
        tree[i].data = i;
    alpha = 0.3;
    auto root = tree_generation(&tree[0], tree.size());
    root->parent = NULL;

    cout << "ǰ�������" << endl;
    pre_order(root);     
    cout << endl << endl;

    cout << "���������" << endl;
    in_order(root);     
    cout << endl << endl;

    cout << "���������" << endl;
    post_order(root);  
    cout << endl << endl;

    cout << "��α�����" << endl;
    level_order(root); 
    cout << endl << endl;

    cout << "��ײ�������Ҷ��" << endl;
    for(auto p = left_most(root); p != NULL; p = next_position(p))
        cout << p->data << ' ';
    cout << endl << endl;

    cout << "��ײ�������Ҷ��" << endl;
    for(auto p = right_most(root); p != NULL; p = prev_position(p))
        cout << p->data << ' ';
    cout << endl << endl;

    return 0;
}

