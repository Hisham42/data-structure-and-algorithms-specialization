#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

double optimal_sequence_dp(int n, vector<int>& mem) {

  int a{0}, b{0}, c{0}, d{0};

  if (n == 1)
  {
    mem[n-1] = 0;
    return 0;
  }
  
  else if (n == 2 || n == 3)
  {
    mem[n-1] = 1;
    return 1;
  }
  else
  {
    if (mem[n-1 - 1] != 0)
    {
      a = mem[n-1 - 1];
    }
    else
    {
      a = optimal_sequence_dp(n - 1, mem);
    }
 
    if (n % 2 == 0 && (n / 2) > 0)
    {
      if (mem[n/2 - 1] != 0)
      {
        b = mem[n/2 - 1];
      }
      else
      {
        b = optimal_sequence_dp(n / 2.0, mem);
      }
    }
    else
    {
      b = 9999;
    }
    
    if (n % 3 == 0 && (n / 3) > 0)
    {
      if (mem[n/3 - 1] != 0)
      {
        c = mem[n/3 - 1];
      }
      else
      {
        c = optimal_sequence_dp(n / 3.0, mem);
      }
    }
    else
    {
      c = 9999;
    }

    int d = std::min({a, b, c}) + 1;
    mem[n-1] = d;
    return d;
  }
}


double optimal_sequence_it(int n, vector<int>& mem) {
  for (size_t i = 1; i <= n; i++)
  {
    if (i == 1)
    {
      mem[i - 1] = 0;
    }
    else if (i == 2 || i == 3)
    {
      mem[i - 1] = 1;
    }
    else
    {

      int a = mem[i-1 - 1] + 1;
      int b;
      if (i % 2 == 0)
      {
        b = mem[i/2 - 1] + 1;
      }
      else
      {
        b = 9999;
      }

      int c;
      if (i % 3 == 0)
      {
        c = mem[i/3 - 1] + 1;
      }
      else
      {
        c = 9999;
      }
      
      int d = std::min({a, b, c});
      mem[i - 1] = d;
    }
  }
  return mem[n - 1];
}

vector<int> back_tracing(int n, vector<int>& mem, vector<std::string>& sequence) {
  
  while(n != 1)
  {
    if (mem[n-1] == mem[n-1 - 1] + 1)
    {
      /* code */
      sequence.push_back("+1");
      n = n - 1;
    }
    else if (mem[n-1] == mem[n/2 - 1] + 1 && n % 2 == 0)
    {
      /* code */
      sequence.push_back("x2");
      n = n/2;
    }
    else if (mem[n-1] == mem[n/3 - 1] + 1 && n % 3 == 0)
    {
      /* code */
      sequence.push_back("x3");
      n = n/3;
    }
  }

  int h = 1;
  vector<int> real_seq;
  real_seq.push_back(h);

  for (int i = sequence.size() - 1; i >= 0; i--)
  {
    if (sequence[i] == "+1")
    {
      h = h + 1;
      real_seq.push_back(h);
    }
    else if (sequence[i] == "x2")
    {
      h = h * 2;
      real_seq.push_back(h);
    }
    if (sequence[i] == "x3")
    {
      h = h * 3;
      real_seq.push_back(h);
    }
  }
  return real_seq;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> mem(n);
  
  vector<std::string> sequence;
  vector<int> real;

  std::cout << optimal_sequence_it(n, mem) << "\n";

  real = back_tracing(n, mem, sequence);

  for (size_t i = 0; i < real.size(); ++i) {
    std::cout << real[i] << " ";
  }

}
