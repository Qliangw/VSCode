#include <iostream>
#include "array.h"

using namespace std;

int test_binary()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout << binary_search_array(2, a, 5) << endl;
    cout << binary_search_array(0, a, 5) << endl;
    cout << binary_search_array(2, a + 2, 3) << endl;
    cout << binary_search_array(0, a, 0) << endl;
    return 0;
}