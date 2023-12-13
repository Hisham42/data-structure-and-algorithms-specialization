#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
  bool touched{false};
};

bool apply(int location, vector<Segment>& segments) {
  bool a = false;

  for (int i = 0; i < segments.size(); i++)
  {
    if (segments[i].touched == false && location >= segments[i].start && location <= segments[i].end)
    {
      segments[i].touched = true;
      a = true;
    }
    
  }
  return a;
}

vector<int> new_solution(vector<Segment> &segments) {
  vector<int> solution;

  std::sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
    return (a.end) < (b.end);
  });

  for (size_t i = 0; i < segments.size(); i++)
  {
    if (segments[i].touched == false && apply(segments[i].end, segments))
    {
      solution.push_back(segments[i].end);
    }
    
  }
  
  return solution;
}




int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = new_solution(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
