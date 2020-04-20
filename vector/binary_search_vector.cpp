//#include <iostream>
#include "myVector.h"

//using namespace std;

int test_binary_vector()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << binary_search_vector(2, v.begin(), 5) << endl;
    cout << binary_search_vector(0, v.begin(), 5) << endl;
    cout << binary_search_vector(2, v.begin() + 2, 3) << endl;
    cout << binary_search_vector(0, v.begin(), 0) << endl;
    cout << binary_search_iterator(2, v.begin(), v.end()) << endl;
    cout << binary_search_iterator(0, v.begin(), v.end()) << endl;
    cout << binary_search_iterator(2, v.begin() + 2, v.end()) << endl;
    cout << binary_search_iterator(0, v.begin(), v.end()) << endl;

    return 0;
}