#include <iostream>
#include <algorithm>
#include <vector>

int get_change(int m, std::vector<int>& coins) {
  //write your code here
  if (m == 1 || m == 3 || m == 4)
  {
    return 1;
  }
  else if (m <= 0)
  {
    return 9999;
  }  
  else if (coins[m] != 0)
  {
    return coins[m];
  }
  else
  {
    coins[m] = std::min({get_change(m - 1, coins), get_change(m - 3, coins), get_change(m - 4, coins)}) + 1;
    return coins[m];
  }
  
}

int main() {
  int m;
  std::cin >> m;
  std::vector<int> coins(m + 1);
  std::cout << get_change(m, coins) << '\n';
}
