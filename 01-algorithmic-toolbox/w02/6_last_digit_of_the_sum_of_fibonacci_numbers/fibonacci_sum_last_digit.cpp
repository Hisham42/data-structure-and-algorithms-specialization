#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

unsigned long long sum_fibonacci_fast(unsigned long long n) {

    unsigned long long sum{0};

    if(n == 0)
    {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else{
        
        n = n % 60;

        unsigned long long* fArray = new unsigned long long[n + 1];
    
        fArray[0] = 0;
        fArray[1] = 1;
        
        if (n > 1)
        {
            sum += 1;
        }
        
        
        for (size_t i = 2; i <= n; i++)
        {
            fArray[i] = fArray[i - 1] + fArray[i - 2];    
            sum += fArray[i];
        }

        delete[] fArray;

        return sum % 10;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << "\n";

    // for (size_t i = 0; i <= 100; i++)
    // {
    std::cout << sum_fibonacci_fast(n) << "  ";
    // }
    
    // std::cout << std::endl;

    // std::string cycle = "0  1  2  4  7  2  0  3  4  8  3  2  6  9  6  6  3  0  4  5  0  6  7  4  2  7  0  8  9  8  8  7  6  4  1  6  8  5  4  0  5  6  2  9  2  2  5  8  4  3  8  2  1  4  6  1  8  0  9  0";

    // int count{0};
    // for (auto &&i : cycle)
    // {
    //     if (i != ' ')
    //     {
    //         count++;
    //     }
        
    // }
    
    // std::cout << count << std::endl;
}
