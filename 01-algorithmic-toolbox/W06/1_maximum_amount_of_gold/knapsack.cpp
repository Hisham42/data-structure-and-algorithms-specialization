#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}


int knapsack(int W, vector<int> &w) {

  std::sort(w.begin(), w.end(), [](int a, int b) {
    return a < b;
  });

  vector<vector<int>> backPack (w.size(), vector<int>(W + 1));

  for (size_t i = 0; i < w.size(); i++)
  {
    backPack[i][0] = 0;
  }

  for (size_t i = 0; i < w.size(); i++)
  {
    int a{-1}, b{-1};
    for (size_t j = 1; j < W + 1; j++)
    {
      if (w[i] <= j && i == 0)
      {
        backPack[i][j] = w[i];
      }
      else if (w[i] <= j)
      {

        if (i >= 1)
        {
          if (backPack[i - 1][j] <= j)
          {
            a = backPack[i - 1][j];
          }
        }
   
        if (i >= 1 && j - w[i] >= 0)
        {
          if (backPack[i - 1][j - w[i]] + w[i] <= j)
          {
            b = backPack[i - 1][j - w[i]] + w[i];
          }
        }
        backPack[i][j] = std::max({a, b});
      }
      else if (i >= 1)
      {
        backPack[i][j] = backPack[i - 1][j];
      }
    }
  }

  // for (size_t i = 0; i < w.size(); i++)
  // {
  //   for (size_t j = 0; j < W + 1; j++)
  //   {
  //     std::cout << std::setw(3) << backPack[i][j];
  //   }
  //   std::cout << std::endl;
  // }

  return backPack[w.size() - 1][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << knapsack(W, w) << '\n';
}
