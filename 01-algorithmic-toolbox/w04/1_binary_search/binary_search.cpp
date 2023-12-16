#include <iostream>
#include <cassert>
#include <vector>

using std::vector;


int binary_search(const vector<int> &a, int x, int left, int right) {
  
  int middle = (right + left) / 2;
  // base case 
  if (right <= left && x != a[right])
  {
    return -1;
  }
  
  if (x == a[middle])
  {
    return middle;
  }
  else if (x > a[middle])
  {
    return binary_search(a, x, middle + 1, right);
  }
  else if (x < a[middle])
  {
    return binary_search(a, x, left, middle - 1);
  }
  else
    return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}



void test_solution() {
  assert(binary_search({0, 2, 4, 6, 8, 10}, 10, 0, 5) == 5);
  assert(binary_search({-1, 2, 9, 11, 80000, 99999, 999999, 9999999}, 10, 0, 7) == -1);
  assert(binary_search({-1, 2, 9, 11, 80000, 99999, 999999, 9999999}, 80000, 0, 7) == 4);
}














int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], 0, a.size() - 1) << ' ';
  }
  // test_solution();
}
