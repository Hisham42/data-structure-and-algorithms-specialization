#include <iostream>
#include <cassert>
int get_change(int m) {
  //write your code here
  // 1 5 10
  int n{0};
  int coins[3] = {10, 5, 1};

  for (size_t i = 0; i < 3; i++)
  {
    int z = m / coins[i];
    m = m - coins[i] * z;
    n += z;
  }
  


  
  return n;
}

void test_solution() {
    assert(get_change(24) == 6);
    assert(get_change(29) == 7);
    assert(get_change(1) == 1);
    assert(get_change(0) == 0);
    assert(get_change(4) == 4);
    assert(get_change(5) == 1);
    assert(get_change(10) == 1);
    assert(get_change(15) == 2);
    assert(get_change(2) == 2);
    assert(get_change(28) == 6);
}
int main() {

  //test_solution();
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
