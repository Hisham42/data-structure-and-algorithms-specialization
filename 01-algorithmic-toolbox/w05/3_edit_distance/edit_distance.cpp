#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

  int rows = str1.size() + 1;
  int columns = str2.size() + 1;
  std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      matrix[i][j] = 0;
    }
  }

  for (size_t i = 0; i < rows; i++)
  {
    matrix[i][0] = i;
  }

  for (size_t i = 0; i < columns; i++)
  {
    matrix[0][i] = i;
  }

  int a{0}, b{0}, c{0};

  for (size_t i = 1; i < rows; i++)
  {
    for (size_t j = 1; j < columns; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        a = matrix[i - 1][j - 1];
      }
      else
      {
        a = matrix[i - 1][j - 1] + 1;
      }

      b = matrix[i - 1][j] + 1;

      c = matrix[i][j - 1] + 1;

      matrix[i][j] = std::min({a, b, c});
    }
  }






  return matrix[rows - 1][columns - 1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
