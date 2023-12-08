#include <iostream>

int fibonacci_fast(int n) {
    
    int* fArray = new int[n + 1];
    

    fArray[0] = 0;
    fArray[1] = 1;

    std::cout << fArray[0] << " " << fArray[1] << " ";

    for (size_t i = 2; i < n + 1; i++)
    {
        fArray[i] = fArray[i - 1] + fArray[i - 2];    
        std::cout << fArray[i] << " ";
    }

    std::cout << std::endl;
    
    int sum = fArray[n];

    delete[] fArray;

    return sum;
}

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    std::cout << current << std::endl;
    return current % 10;
}

int get_fibonacci_last_digit_magic(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    
    return current;
}

int main() {
    int n;
    std::cin >> n;
    //fibonacci_fast(n);
    int c = get_fibonacci_last_digit_magic(n);
    std::cout << c << '\n';
    }
