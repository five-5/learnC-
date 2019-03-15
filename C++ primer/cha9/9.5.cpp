#include <iostream>
#include <vector>

std::vector<int>::const_iterator findX(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last, int x){
    while(first != last){
        if (*first == x){
            return first;
        }
        ++first;
    }
    return first;
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
    std::vector<int>::const_iterator it = findX(nums.begin(), nums.end(), x);
    if (it == nums.end()){
        std::cout << "can not find it!!!" << std::endl;
    } else{
        std::cout << "find it!!! It's " << *it <<  std::endl;
    }
    return 0;
}
