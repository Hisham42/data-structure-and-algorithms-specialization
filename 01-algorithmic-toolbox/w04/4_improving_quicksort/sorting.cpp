#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}


void quick_sort(vector<int> &a, int l, int r) {

  if (l == r)
  {
    return;
  }
  
  int partition = l;
  
  int j{partition};

  for (int i = r; i > j, j < i; i--)
  {
    if (a[i] < a[partition])
    {
      j++;
      swap(a[j], a[i]);
      i++;
    }
  }

  swap(a[partition], a[j]);

  partition = j;

  if (partition != r)
  {
    quick_sort(a, partition + 1, r);
  }

  if (partition != l)
  {
    quick_sort(a, l, partition - 1);
  }

}

void quick_sort_mid(vector<int> &a, int l, int r) {

  if (r - l <= 0)
  {
    return;
  }

  int partitionPoint = l + rand() % (r - l + 1);
  // int partitionPoint = l + (r - l) / 2;
  int partitionPointValue = a[partitionPoint];
  int i = l + 1;
  int j = r;

  std::swap(a[l], a[partitionPoint]);

  while (true)
  {
    for (; i < r; i++)
    {
      if (a[i] >= partitionPointValue)
      { 
        break;
      }
    }
    for (; j > l; j--)
    {
      if (a[j] < partitionPointValue)
      {
        break;
      }
    }
    if (i >= j)
    {
      break;
    }
    else
    {
      std::swap(a[i], a[j]);
      i++;
      j--;
    }
    
  }

  std::swap(a[l], a[j]);

  
  
  int newRight = j - 1;
  int newLeft = j + 1;
  
  while (a[newRight] == a[j] && newRight > l)
  {
    newRight--;
  }
  
  while (a[newLeft] == a[j] && newLeft < r)
  {
    newLeft++;
  }

  quick_sort_mid(a, l, newRight);
  quick_sort_mid(a, newLeft, r);

}


void test_solution() {

  vector<int> a = {4, 5, 3, 6, 2, 1};
  vector<int> b = {1, 2, 3, 4, 5, 6};
  quick_sort_mid(a, 0, a.size() - 1);
  assert(a == b);

  vector<int> c = {4, 5, 4, 4, 5, 5, 54, 5};
  vector<int> d = {4, 4, 4, 5, 5, 5, 5, 54};
  quick_sort_mid(c, 0, c.size() - 1);
  assert(c == d);

  vector<int> e = {1, 8, 8, 7, 8, 8, 9, 7, 8, 12, 1, 2};
  vector<int> f = {1, 1, 2, 7, 7, 8, 8, 8, 8, 8, 9, 12};
  quick_sort_mid(e, 0, e.size() - 1);
  assert(e == f);

  e = {1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 2};
  f = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3};
  quick_sort_mid(e, 0, e.size() - 1);
  assert(e == f);
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
   
  }

  quick_sort_mid(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  // test_solution();
}