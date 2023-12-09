#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

unsigned long long sum_fibonacci_fast(unsigned long long from, unsigned long long to) {

    unsigned long long sum{0};
    if (to >= from)
    {
   
    
        if(to == 0)
        {
            return 0;
        }
        else if (to == 1) {
            return 1;
        }
        else{
            
            to = to % 60;
            from = from % 60;

            while (to < from)
            {
                to += 60;
            }
            

            unsigned long long* fArray = new unsigned long long[to + 1];
        
            
            for (size_t i = 0; i <= to; i++)
            {
                if (i == 0)
                {
                    fArray[i] = 0;
                }

                else if (i == 1)
                {
                    fArray[i] = 1;
                }
                else
                {
                    fArray[i] = fArray[i - 1] + fArray[i - 2];
                }   

                if (i >= from)
                {
                    sum += fArray[i];
                }
                
            }

            delete[] fArray;
            }
    }

   

    return sum % 10;
    
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << sum_fibonacci_fast(from, to) << '\n';
}
