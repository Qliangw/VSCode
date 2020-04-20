#ifndef _MYALGORITHM_H
#define _MYALGORITHM_H

#include <iostream>
#include <vector>

using namespace std;
size_t itertive_Collatz(size_t n);
size_t memoized_Collatz(vector<size_t>&V,size_t n);
void test_memoized_Collatz();

#endif