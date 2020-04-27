#ifndef _MYVECTOR_H
#define _MYVECTOR_H

#include <iostream>
#include <vector>

using namespace std;
// Ϊ�˼�����, û��ʹ��vector<T>::const_iterator.
template <typename T>
bool binary_search_vector(const T& key, typename vector<T>::iterator data,
                          size_t N)
{
  size_t low = 0;
  size_t high = N;
  while (low < high)
  {
    size_t mid = low + (high - low) / 2;
    if (key < *(data + mid))		// С��ȥǰ�벿��
      high = mid;
    else if (*(data + mid) < key)	// ����ȥǰ�벿��
      low = mid + 1;
    else
      return true;
  }
  return false;
}

// Ϊ�˼�����, û��ʹ��vector<T>::const_iterator.
template <typename T, typename iterator>
bool binary_search_iterator(const T& key, iterator L, iterator R)
{
  while (L < R)
  {
    iterator M = L + (R - L) / 2;
    if (key < *M)       // С��ȥǰ�벿�ּ�������.
      R = M;
    else if (*M < key)  // ����ȥ��벿�ּ�������.
      L = M + 1;
    else
      return true;
  }
  return false;
}

template <typename T>
void print_all(const T& S)
{
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
}

int test_binary_vector();
void sortedVector_and_unsortedVector();
void vector_example();
void doubling();

void int_push_back();

void pointer_push_back();

void struct_push_back();

#endif