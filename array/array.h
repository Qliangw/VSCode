#ifndef _ARRAY_H
#define _ARRAY_H

template<typename T>
int binary_search_array(const T & key, const T data[], int N)
{
    if(N < 0)
        return -1;
    int low = 0;
    int high = N - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(key < data[mid])
            high = mid - 1;
        else if (data[mid] < key)
            low = mid + 1;
        else
            return mid;
        
    }
    return -1;
}

int diagonal();
int arrayAndVector();
int test_binary();

#endif