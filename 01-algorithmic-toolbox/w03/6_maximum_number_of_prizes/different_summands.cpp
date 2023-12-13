#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here

  int sum = 0;
  int i = 0;
  while (sum < n)
  {
    i++;
    summands.push_back(i);
    sum += i;
  }

  if (sum == n)
  {
    return summands;

  }
  else
  {
    sum = sum - summands[summands.size() - 1];
    summands.pop_back();

    int lastValue = n - sum;
    summands[summands.size() - 1] += lastValue;
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
