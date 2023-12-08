#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}


long long maxPairwiseProductFaster(const std::vector<int>& numbers) {
    int maxNumber{-1};
    int maxNumberIndex{-1};
    
    int preMaxNumber{-1};

    // find the max num

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (maxNumber < numbers[i])
        {
            maxNumber = numbers[i];
            maxNumberIndex = i;
        }
    }


    for (size_t j = 0; j < numbers.size(); j++)
    {
        if (j != maxNumberIndex && preMaxNumber < numbers[j])
        {
            preMaxNumber = numbers[j];
        }
        
    }
    return (long long)maxNumber * preMaxNumber;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << maxPairwiseProductFaster(numbers) << "\n";
    return 0;
}
