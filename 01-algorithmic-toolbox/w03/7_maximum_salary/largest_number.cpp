#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using std::vector;
using std::string;

int find_max_length(vector<string> a) {
  int length = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (length < a[i].size())
    {
      length = a[i].size();
    }
    
  }
  return length;
}

void edit_string(vector<int>& newStr, vector<string> oldStr, int length) {
  for (int i = 0; i < oldStr.size(); i++)
  {
    while(oldStr[i].size() < length)
    {
      oldStr[i].push_back(oldStr[i][0]);
    }

    newStr.push_back(std::stoi(oldStr[i])); 
  }
  
}

void sort(vector<string>& a, vector<int>& a_edited) {
  for (int i = 0; i < a_edited.size(); i++)
  {
    for (int j = i + 1; j < a_edited.size(); j++)
    {
    
      if (a_edited[i] < a_edited[j] || (
        a_edited[i] == a_edited[j] &&
        (
          (int(a[i][0]) < int(a[j][1]) && a[i].size() > a[j].size()) 
          ||(int(a[i][0]) > int(a[j][1]) && a[i].size() < a[j].size())
          )
        )
      )
      
      {
        int temp = a_edited[i];
        a_edited[i] = a_edited[j];
        a_edited[j] = temp;

        std::string tempStr = a[i];
        a[i] = a[j];
        a[j] = tempStr;
      }
  
    }   
  }
  
}



void clean(vector<string>& a) {
  for (size_t i = 0; i < a.size(); i++)
  {
    for (size_t j = 0; j < a[i].size(); j++)
    {
      if (a[i][j] == '0' && a[i].size() != 1)
      {
        a[i].erase(a[i].begin());
      }
      else
      {
        break;
      }      
    }
  }
}

string largest_number(vector<string>& a) {
  //write your code here
  std::stringstream ret;

  vector<int> a_edited;

  clean(a);

  int max_length = find_max_length(a);

  edit_string(a_edited, a, max_length);


  sort(a, a_edited);


  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;

  return result;
}


void testSolution() {
  vector<string> a = {"91", "919"};
  vector<string> b = {"919", "91"};
  vector<string> c = {"34", "343"};
  vector<string> d = {"343", "34"};

  assert(largest_number(a) == "91991");
  assert(largest_number(b) == "91991");
  assert(largest_number(c) == "34343");
  assert(largest_number(d) == "34343");


}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  // testSolution();
}
