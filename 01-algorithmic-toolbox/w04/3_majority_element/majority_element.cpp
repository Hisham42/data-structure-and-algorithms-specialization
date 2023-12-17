#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

vector<int> merge_sort(vector<int>& a, int left, int right) {


  int mid = (right - left) / 2;
  
  if (right > left)
  {
    vector<int> merged;
    vector<int> l;
    vector<int> r;

    
      for (size_t i = 0; i <= mid; i++)
      {
        l.push_back(a[i]);
      }

      for (size_t j = mid + 1; j < a.size(); j++)
      {
        r.push_back(a[j]);
        
      }

      l = merge_sort(l, 0, mid);
      r = merge_sort(r, mid + 1, a.size() - 1);
      

      // merging
      int q{0}, w{0};
      for (; merged.size() < l.size() + r.size();)
      {
        if (q == l.size() && w < r.size())
        {
          merged.push_back(r[w]);
          w++;
        }

        else if (w == r.size() && q < l.size())
        {
          merged.push_back(l[q]);
          q++;
        }

        else if (q < l.size() && w < r.size())
        {
          if (l[q] >= r[w])
          {
            merged.push_back(l[q]);
            q++;
          }
          else
          {
            merged.push_back(r[w]);
            w++;
          }
          
        }

      }
    return merged;
  }
  else
    return a;
    
}


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here

  // std::sort(a.begin(), a.end(), [](int a, int b) {
  //   return a < b;
  // });

  a = merge_sort(a, 0, a.size() - 1);

  int count{1};

  for (size_t i = 0; i < a.size(); i++)
  {
    if (count > (a.size() / 2))
    {
      return 1;
    }
    
    if (a[i] == a[i+1])
    {
      count++;
    }
    else
      count = 1;
  }
  
  return -1;
}

void test_solution() {
  vector<int> a = {2, 3, 9, 2, 2};
  assert(get_majority_element(a, 0, 4) == 1);

  vector<int> b = {1, 2, 3, 1};
  assert(get_majority_element(b, 0, 3) == -1);
}

void test_solution2() {
  vector<int> a = {2, 3, 9, 2, 2, 10, 20, 45, 74};
  vector<int> a_sorted = merge_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cout << a_sorted[i] << " ";
  }
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
  // test_solution();
}
