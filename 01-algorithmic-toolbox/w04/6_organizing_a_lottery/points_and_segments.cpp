#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  return cnt;
}

//n^2
vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

void test_solution() {

  vector<int> starts = {00, 07, 17};
  vector<int> ends   = {05, 10, 22}; 
  vector<int> points = {5, 10};
  vector<int> result = {1, 1};
  // assert(naive_count_segments(starts, ends, points) == result);
  assert(naive_count_segments(starts, ends, points) == fast_count_segments(starts, ends, points));

}


int main() {
  // int n, m;
  // std::cin >> n >> m;
  // vector<int> starts(n), ends(n);
  // for (size_t i = 0; i < starts.size(); i++) {
  //   std::cin >> starts[i] >> ends[i];
  // }
  // vector<int> points(m);
  // for (size_t i = 0; i < points.size(); i++) {
  //   std::cin >> points[i];
  // }
  // //use fast_count_segments
  // vector<int> cnt = naive_count_segments(starts, ends, points);
  // for (size_t i = 0; i < cnt.size(); i++) {
  //   std::cout << cnt[i] << ' ';
  // }

  test_solution();
}
