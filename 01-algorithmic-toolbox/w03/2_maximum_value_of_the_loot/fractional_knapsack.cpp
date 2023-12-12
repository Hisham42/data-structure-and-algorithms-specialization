#include <iostream>
#include <vector>
#include <cassert>

using std::vector;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  bool noWeightsleft{false};

  // write your code here
  while (capacity > 0 || noWeightsleft == true)
  {
    // find max value
    int index{0};
    double maxValue{0};
    for (size_t i = 0; i < values.size(); i++)
    {
      if (weights[i] > 0)
      {
        if (maxValue < double(values[i]) / weights[i])
        {
          maxValue = double(values[i]) / weights[i];
          index = i;
        }
      }
    }

    if (weights[index] == 0)
    {
      noWeightsleft = true;
      break;
    }
    

    if (capacity <= weights[index])
    {
      value += capacity * double(values[index]) / weights[index];
      capacity = 0;
      weights[index] = weights[index] - capacity;
    }
    else
    {
      value += values[index];
      capacity = capacity - weights[index];
      weights[index] = 0;
    }
  }
  


  return value;
}

void testSolution() {
  assert(get_optimal_value(50, {20, 50, 30}, {60, 100, 120}) == 180);
  assert(get_optimal_value(10, {30}, {600}) == 200);
  assert(get_optimal_value(100, {30, 50, 20}, {80, 100, 60}) == 240);

  assert(get_optimal_value(2000000, {2000000, 2000000, 2000000}, {200, 100, 60}) == 200);
  
}

int main() {
  // testSolution();
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
