#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

vector<int> merge_sort(vector<int>& a, int left, int right, int& inversions) {
  
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

      l = merge_sort(l, 0, mid, inversions);
      r = merge_sort(r, mid + 1, a.size() - 1, inversions);
      
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
            int index = w;
            for (index = w; index < r.size(); index++)
            {
              if (r[index] < r[w] || r[index] < l[q])
              {
                break;
              }
            }
            
            inversions += r.size() - index;
            
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

int calculate_inversions(vector<int>& a, int left, int right){
  int inversions{0};
  merge_sort(a, left, right, inversions);
  return inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

long long get_number_of_inversions_naive(vector<int> &a) {
  long long number_of_inversions = 0;
  
  for (size_t i = 0; i < a.size(); i++)
  {
    for (size_t j = i; j < a.size(); j++)
    {
      if (i < j && a[i] > a[j])
      {
        number_of_inversions++;
      }
      
    }
    
  }
  return number_of_inversions;
}

void test_solution() {

  vector<int> a = {3, 2, 5, 9, 4};
  int b = 3;

  assert(get_number_of_inversions_naive(a) == calculate_inversions(a, 0, a.size() -1));

  a = {9, 7, 5, 4, 2, 1};
  b = 15;

  assert(get_number_of_inversions_naive(a) == calculate_inversions(a, 0, a.size() -1));

  a = {2, 3, 9, 2, 9};
  b = 2;

  assert(get_number_of_inversions_naive(a) == calculate_inversions(a, 0, a.size() -1));


  a = {1, 2, 3, 4, 5, 9, 10};
  b = 0;

  assert(get_number_of_inversions_naive(a) == calculate_inversions(a, 0, a.size() -1));
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  
  std::cout << calculate_inversions(a, 0, a.size() - 1) << '\n';

  // test_olution();
}