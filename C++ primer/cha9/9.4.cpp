#include <iostream>
#include <vector>

bool findX(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last, int x){
    while(first != last){
        if (*first == x){
            return true;
        }
        ++first;
    }
    return false;
}

int main()
{
    std::vector<int> nums;
    int n;
    std::cin >> n;
    nums.resize(n);
    for(size_t i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }
    std::cout << "please enter what you want to find: ";
    int x;
    std::cin >> x;
    std::cout << ((findX(nums.begin(), nums.end(), x))?"find it!":"can not find it !!!") << std::endl;
    return 0;
}
