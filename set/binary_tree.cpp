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
void pre_order(iterator p)
{
    if (p != NULL)
    {
        cout << p->data << ' ';
        pre_order(p->left);
        pre_order(p->right);
    }
}

template <typename iterator> 
void in_order(iterator p)
{
    if(p != NULL)
    {
        in_order(p->left);
        cout << p->data << ' ';
        in_order(p->right);
    }
}

template <typename iterator>  
void post_order(iterator p)
{
    if(p != NULL)
    {
        post_order(p->left);
        post_order(p->right);
        cout << p->data << ' ';
    }
}

template <typename iterator>  
void level_order(iterator)

