#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  double result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    
    // calculate price index
    int price_index{0};
    double max_price{0};

    int click_index{0};
    int max_click{0};

    for (size_t j = 0; j < a.size(); j++)
    {
      if (max_price < a[j])
      {
        max_price = a[j];
        price_index = j;
      }

      if (max_click < b[j])
      {
        max_click = b[j];
        click_index = j;
      }
      
    }
    
    result += max_click * max_price;

    a[price_index] = 0;
    b[click_index] = 0;

  }

  return result;
}

void testSolution() {

  assert(max_dot_product({23}, {39}) == 897);
  assert(max_dot_product({2, 3, 9}, {7, 4, 2}) == 79);

}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  // testSolution();
}
