#ifndef _MYSET_H
#define _MYSET_H

#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
void print_all(const T& S)
{
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
}

void set_example();
void order_statistics_set();
void descriptiong();

#endif