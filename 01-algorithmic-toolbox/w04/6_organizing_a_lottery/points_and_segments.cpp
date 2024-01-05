#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <algorithm>

using std::vector;


struct Segment
{
  int value;
  char type;
  int index;
};



vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here


  vector<Segment> segments;

  for (int i = 0; i < starts.size(); i++)
  {
    Segment s = {starts[i], 'a' , 0};
    segments.push_back(s);
  }

  for (int i = 0; i < ends.size(); i++)
  {
    Segment s = {ends[i], 'z' , 0};
    segments.push_back(s);
  }

  for (int i = 0; i < points.size(); i++)
  {
    Segment s = {points[i], 'p' , i};
    segments.push_back(s);
  }

  // sort starts and ends
 
  std::sort(segments.begin(), segments.end(), [](Segment a, Segment b){
    if (a.value == b.value)
    {
      return a.type < b.type;
    }
    else
      return a.value < b.value;
  });

  int counter = 0;
  for (size_t i = 0; i < segments.size(); i++)
  {
    if (segments[i].type == 'a')
    {
      counter++;
    }
    else if (segments[i].type == 'z')
    {
      counter--;
    }
    else
    {
      cnt[segments[i].index] = counter;
    }
  }


  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());

  for (size_t i = 0; i < starts.size(); i++)
  {
    if (starts[i] > ends[i])
    {
      std::swap(starts[i], ends[i]);
    }
    
  }
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }

 
  return cnt;
}

void test_solution() {

    vector<int> starts = {-10};
    vector<int> ends = {10};
    vector<int> points = {-100, 100, 0};

    vector<int> result = naive_count_segments(starts, ends, points);
    vector<int> result2 = fast_count_segments(starts, ends, points);

    assert(result == fast_count_segments(starts, ends, points));

    std::cout << "\n" << "test_solution() IS WORKING ----------------------------------------------------------------" << std::endl;
}

void test_solution_2() {
    std::srand(std::time(0));

    int b = 0;
    while (b!= 10000) {  // Adjust the maximum number of iterations as needed
        int randomValue = (std::rand() % (RAND_MAX - 1) + 1) % 500 + 1;

        vector<int> starts;
        vector<int> ends;
        vector<int> points;

        for (size_t i = 0; i < randomValue; i++) {
            starts.push_back(static_cast<int>(rand() % 200 - 200));
            ends.push_back(static_cast<int>(rand() % 200 - 200));
            points.push_back(static_cast<int>(rand() % 200 - 200));
        }

        std::cout << starts.size() << "-------------------------------" << std::endl;

        
        // vector<long long> result = naive_count_segments(starts, ends, points);
        // assert(result == h_Solution_1(starts, ends, points));
        for (size_t i = 0; i < starts.size(); i++)
        {
          std::cout << starts[i] << " ";
        }

          std::cout << std::endl;

          for (size_t i = 0; i < ends.size(); i++)
        {
          std::cout << ends[i] << " ";
        }

          std::cout << std::endl;

          for (size_t i = 0; i < starts.size(); i++)
        {
          std::cout << points[i] << " ";
        }

          std::cout << std::endl;

        
        fast_count_segments(starts, ends, points);

        std::cout << "Iteration: " << b << " - " << " working fine" << std::endl;
        b++;
    }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }

  // test_solution();
}
