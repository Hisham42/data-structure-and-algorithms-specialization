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
  
  if (x == a[middle] && a[middle - 1] != x)
  {
    return middle;
  }
  else if (x > a[middle])
  {
    return binary_search(a, x, middle + 1, right);
  }
  else if (x < a[middle] || a[middle - 1] == x)
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
  assert(binary_search({2, 4, 4, 4, 7, 7, 9}, 4, 0, 6) == 1);
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
    std::cout << binary_search(a, b[i], 0 , a.size() - 1) << ' ';
  }

  // test_solution();
}

