#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::vector;

struct Point
{
  int x;
  int y;
};


int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  vector<bool> c(b.size());
  vector<bool> d(a.size());
  
  int rows = a.size();
  int columns = b.size();
  vector<vector<int>> matrix(rows, vector<int>(columns));
  vector<Point> points;


  int di{0};
  Point p;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      if (a[i] == b[j])
      {
        p.x = i;
        p.y = j;
        points.push_back(p);
      }
      
    }
  }
  
  for (size_t bigI = 0; bigI < points.size(); bigI++)
  {
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        matrix[i][j] = 0;
      }
    }
    for (size_t i = 0; i < c.size(); i++)
    {
      c[i] = false;
    }
    for (size_t i = 0; i < d.size(); i++)
    {
      d[i] = false;
    }
    
  
    for (size_t j = points[bigI].y; j < columns; j++)
    {
      if (j > points[bigI].y)
      {
        matrix[points[bigI].x][j] = matrix[points[bigI].x] [j - 1];
      }
      
      if (a[points[bigI].x] == b[j] && !d[points[bigI].x] && !c[j])
      {
        matrix[points[bigI].x][j]++;
        c[j] = true;
        d[points[bigI].x] = true;
      }
    }

    for (size_t i = points[bigI].x; i < rows; i++)
    {
      if (i > points[bigI].x)
      {
        matrix[i][points[bigI].y] = matrix[i - 1] [points[bigI].y];
      }
      if (a[i] == b[points[bigI].y] && !c[points[bigI].y] && !d[i])
      {
        matrix[i][points[bigI].y]++;
        c[points[bigI].y] = true;
        d[i] = true;
      }
    }

    for (size_t i = 1; i < rows; i++)
    {
      for (size_t j = points[bigI].y + 1; j < columns; j++)
      {
        int s1 = matrix[i - 1][j];
        int s2 = matrix[i][j- 1];

        matrix[i][j] = std::max(s1, s2);

        if (a[i] == b[j] && !d[i] && !c[j])
        {
          matrix[i][j]++;
          c[j] = true;
          d[i] = true;
        
        }
      }
    }
  
    if (di < matrix[rows - 1][columns - 1])
    {
      di = matrix[rows - 1][columns - 1];
    }
  
  //  for (size_t i = 0; i < rows; i++)
  //   {
  //     for (size_t j = 0; j < columns; j++)
  //     {
  //       std::cout << std::setw(3) << matrix[i][j]; 
  //     }
  //     std::cout << std::endl;
      
  //   }
    // std::cout << di << std::endl;
  }

  return di;
}

int lcs_dp(vector<int> &a, vector<int> &b, int x, int y, vector<vector<int>>& matrix) {


  if (x >= a.size() || y >= b.size())
  {
    return 0;
  }
  else if (a[x] == b[y])
  {
    if (matrix[x][y] != -1)
    {
      return matrix[x][y];
    }
    else
    {
      matrix[x][y] =  1 + lcs_dp(a, b, x + 1, y + 1, matrix);
      return matrix[x][y];
    }
  }
  else
  {
    if (matrix[x][y] != -1)
    { 
      return matrix[x][y];
    }
    else
    {
      matrix[x][y] = std::max({lcs_dp(a, b, x, y + 1, matrix), lcs_dp(a, b, x + 1, y, matrix)});
      return matrix[x][y];
    }
  }

  

}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  int rows = a.size();
  int columns = b.size();
  vector<vector<int>> matrix(rows, vector<int>(columns));

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      matrix[i][j] = -1;
    }
    
  }

  std::cout << lcs_dp(a, b, 0, 0, matrix) << std::endl;
}
