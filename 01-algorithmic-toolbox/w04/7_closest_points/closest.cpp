#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;


double minimal_distance_naive(vector<int> x, vector<int> y) {
  //write your code here
  double distance{0};
  double d{0};
  bool start = false;
  for (size_t i = 0; i < x.size(); i++)
  {
    for (size_t j = 0; j < y.size(); j++)
    {
      if (i != j)
      {
        distance = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
        if (start == false)
        {
          d = distance;
          start = true;
        }
        
        if (d > distance)
        {
          d = distance;
        }
      }
    }
  }
  
  return d;
}


struct Point
{
  int x;
  int y;
};

double minimal_distance(vector<Point>& points, vector<Point>& Y) {
  //write your code here
  //base case
  
  int l = 0;
  int r = points.size() - 1;

  auto p = points.begin();

  if (r - l<= 1)
  {
    return sqrt(pow((points[r].x - points[l].x), 2) + pow((points[r].y - points[l].y), 2));
  }

  vector<Point> S1;
  vector<Point> S2;
  vector<Point> s_strip;

  
  int mid = (r + l ) / 2;

  for (size_t i = 0; i <= mid; i++)
  {
    S1.push_back(points[i]);
  }

  if (points.size() % 2 == 1)
  {
    S2.push_back(points[mid]);
  }

  for (size_t i = mid + 1; i < points.size(); i++)
  {
    S2.push_back(points[i]);
  }

  vector<Point> Y1;
  vector<Point> Y2;
  for (size_t i = 0; i < Y.size(); i++)
  {
    if (Y[i].x <= points[mid].x)
    {
      Y1.push_back(Y[i]);
    }
    else
    {
      Y2.push_back(Y[i]);
    }
  }
  
  double d1 = minimal_distance(S1, Y1);

  double d2 = minimal_distance(S2, Y2);

  double dMin;

  dMin = std::min(d1, d2);

  double xStrip;

  if (points.size() % 2 == 0)
  {
    xStrip = (S1[S1.size() - 1].x + S2[0].x ) / 2.0;
  }
  else
  {
    xStrip = S1[S1.size() - 1].x;
  }

  if (points.size() % 2 == 1)
  {
    S1.pop_back();
  }
    
  for (size_t i = 0; i < Y.size(); i++)
  {
    if (Y[i].x >= S1[0].x && Y[i].x <= S2[S2.size() - 1].x)
    {
      if (abs(Y[i].x - xStrip) < dMin)
      {
        s_strip.push_back(Y[i]);
      }
    }
  }
  
  if (s_strip.size() > 1)
  {
    double distance;

    for (size_t i = 0; i < s_strip.size() - 1; i++)
    {
      for (size_t j = i + 1; j < i + 6 && j < s_strip.size(); j++)
      {
        distance = sqrt(pow((s_strip[i].x - s_strip[j].x), 2) + pow((s_strip[i].y - s_strip[j].y), 2));
        dMin = std::min(dMin, distance);
        
      }
    }
    
  }
 
  return dMin;
}

double minimal_distance_G(vector<int>& x, vector<int>& y) {

  vector<Point> points(x.size());
   vector<Point> Y;

  for (size_t i = 0; i < points.size(); i++)
  {
    points[i].x = x[i];
    points[i].y = y[i];
    
  }

  Y = points;

  std::sort(points.begin(), points.end(), [](Point a, Point b){  
    return a.x < b.x;
  });

  std::sort(Y.begin(), Y.end(), [](Point a, Point b){  
    return a.y > b.y;
  });

  // std::sort(points.begin(), points.end(), [](Point a, Point b){  
  //   return a.y > b.y;
  // });

  return minimal_distance(points, Y);
}

void test_solution() {

  vector<int> x = {-2, 2, -1, -2};
  vector<int> y = {-1, -1, 0, -3};

  x = {7, 5, 4, 5, 4, 1, 4, 5, 8, 1};
  y = {6, -6, -10, -10, -1, -1, 6, 2, -2, 5};

  std::cout << minimal_distance_G(x, y) << std::endl;
  std::cout << minimal_distance_naive(x, y) << std::endl;
  assert(minimal_distance_G(x, y) == minimal_distance_naive(x, y));

  int b = 1;

  srand(time(0));

  int testSize = 99;

  while (true)
  {   
    
    std::cout << "Test Case " << b << std::endl;


    size_t size = rand() % testSize + 1;

    vector<int> x1(size);
    vector<int> y1(size);

    for (size_t i = 0; i < size; i++)
    {
      x1[i] = rand() % (testSize * 2) - testSize;
      y1[i] = rand() % (testSize * 2) - testSize;
    }

    if(minimal_distance_G(x1, y1) != minimal_distance_naive(x1, y1)) 
    {
      std::cerr << "Assertion Error : x = [";
      for (const auto& elem : x1) {
          std::cerr << elem << ", ";
      }
      std::cerr << "], y = [";
      for (const auto& elem : y1) {
          std::cerr << elem << ", ";
      }
      std::cerr << "]\n";

      std::cerr << "D&C: " << minimal_distance_G(x1, y1) << "\n";

      std::cerr << "Naive: " << minimal_distance_naive(x1, y1) << "\n";
      break;
    }

    b++;

    std::cout << "-------------------------------------" << std::endl;
  }
}

int main() {
  // size_t n;
  // std::cin >> n;
  // vector<int> x(n);
  // vector<int> y(n);
  // for (size_t i = 0; i < n; i++) {
  //   std::cin >> x[i] >> y[i];
  // }
  // std::cout << std::fixed;
  // std::cout << std::setprecision(9) << minimal_distance_G(x, y) << "\n";

  test_solution();
}
