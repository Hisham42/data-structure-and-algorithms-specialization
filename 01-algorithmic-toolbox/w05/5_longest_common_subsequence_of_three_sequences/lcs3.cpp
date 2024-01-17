#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  return std::min(std::min(a.size(), b.size()), c.size());
}

int lcs3_dp(vector<int> &a, vector<int> &b, vector<int> &c, int x, int y, int z, vector<vector<vector<int>>>& matrix) {


  if (x >= a.size() || y >= b.size() || z >= c.size())
  {
    return 0;
  }
  else if (a[x] == b[y] && b[y] == c[z])
  {
    if (matrix[x][y][z] != -1)
    {
      return matrix[x][y][z];
    }
    else
    {
      matrix[x][y][z] =  1 + lcs3_dp(a, b, c, x + 1, y + 1, z + 1, matrix);
      return matrix[x][y][z];
    }
  }
  else
  {
    if (matrix[x][y][z] != -1)
    { 
      return matrix[x][y][z];
    }
    else
    {
      matrix[x][y][z] = std::max({
        lcs3_dp(a, b, c, x    , y + 1 , z     , matrix),
        lcs3_dp(a, b, c, x + 1, y     , z     , matrix),
        lcs3_dp(a, b, c, x    , y     , z + 1 , matrix),
        lcs3_dp(a, b, c, x + 1, y + 1 , z     , matrix),
        lcs3_dp(a, b, c, x + 1, y     , z + 1 , matrix),
        lcs3_dp(a, b, c, x    , y + 1 , z + 1 , matrix)
        });
      return matrix[x][y][z];
    }
  }

  

}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }



  int rows = a.size();
  int columns = b.size();
  int height = c.size();


  vector<vector<vector<int>>> matrix(rows, (vector<vector<int>>(columns, vector<int>(height))));

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      for (size_t k = 0; k < height; k++)
      {
        matrix[i][j][k] = -1;
      }
    }
  }
  std::cout << lcs3_dp(a, b, c, 0, 0, 0, matrix) << std::endl;
}
