#include <iostream>

int calculate_cycle_difference(int mod);


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


int get_fibonacci_huge_magic(const long long& n, int mod) {
    
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % mod;
    }
    
    return current;
}

int get_fibonacci_huge_magic_new(const long long& n, int mod, int cycle) {


    
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    int newN = n % cycle;

    for (long long i = 0; i < newN - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % mod;
    }
    
    return current;
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

int calculate_cycle_difference(int mod) {

    int pattern[4];

    for (size_t i = 0; i < 4; i++)
    {
        pattern[i] = get_fibonacci_huge_magic(i, mod);
    }

    for (size_t i = 4; i < 999999; i++)
    {
        if (
            pattern[0] == get_fibonacci_huge_magic(i, mod) &&
            pattern[1] == get_fibonacci_huge_magic(i + 1, mod) &&
            pattern[2] == get_fibonacci_huge_magic(i + 2, mod) &&
            pattern[3] == get_fibonacci_huge_magic(i + 3, mod)
        )
        {
            return i;
        }
        
    }
    
    return -1;

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << fibonacci_fast(n) << std::endl;

    //std::cout << get_fibonacci_huge_magic(0, 6) << std::endl;

    

    //std::cout << "\n"<< get_fibonacci_huge_magic(19, 5) << "\n";
    //std::cout << get_fibonacci_huge_magic(135, 5) << "\n";
    //int x{239};

    //long long y{2816213588};

    int diff = calculate_cycle_difference(m);


    //std::cout << get_fibonacci_huge_magic_new(115, 1000, diff) << std::endl;

    //std::cout << get_fibonacci_huge_magic_new(2816213588, 239, diff) << std::endl;

    std::cout << get_fibonacci_huge_magic_new(n, m, diff) << std::endl;
    
    
}
