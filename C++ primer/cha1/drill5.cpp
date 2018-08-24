// 统计输入中每个值连续出现了多少次
#include <iostream>

int main()
{
    int currVal, val;

    if (std::cin >> currVal){
        int times = 1;
        while(std::cin >> val){
            if (currVal == val)
                times++;
            else{
                std::cout << currVal << " occurs "
                          << times   << " times"
                          << std::endl;
                currVal = val;
                times = 1;
            }
        }
         std::cout << currVal << " occurs "
                          << times   << " times"
                          << std::endl;
    }

    return 0;
}
