#include <iostream>
#include <math.h>
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

unsigned long long fibonacci_fast(unsigned long long n) {

    
    
    
    if(n == 0)
    {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else{
         unsigned long long* fArray = new unsigned long long[n + 1];
    
    
        fArray[0] = 0;
        fArray[1] = 1;

        //std::cout << fArray[0] % 10 << " " << fArray[1] % 10 << " ";

        for (size_t i = 2; i < n + 1; i++)
        {
            fArray[i] = fArray[i - 1] + fArray[i - 2];    
            //std::cout << fArray[i] % 10 << " ";
        }

        //std::cout << std::endl;
        
        unsigned long long sum = fArray[n];

        delete[] fArray;

        return sum;
    }
   
}

int fibonacci_sum_squares_magic(long long n) {

    std::string cycle = "0 1 2 6 5 0 4 3 4 0 5 6 2 1 0 0 9 8 4 5 0 6 7 6 0 5 4 8 9 0";
    int cycle_count{0};

    for (auto &&i : cycle)
    {
        if (i !=' ')
        {
            cycle_count++;
        }
        
    }
    
    n = n % cycle_count;
    
    return fibonacci_fast(n) % 10 * fibonacci_fast(n + 1) % 10;

}



int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_magic(n);
    // unsigned long long int sum{0};

    // // for (size_t i = 0; i < 20; i++)
    // // {
    // //     sum += std::pow(fibonacci_fast(i), 2);
        
    // // }

    // // std::cout << sum << " " << "\n";

    // for (size_t i = 0; i < 100; i++)
    // {
    //     std::cout << fibonacci_sum_squares_magic(i) << " ";
    // }
    

    
}
