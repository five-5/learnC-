// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.27 :
// delete odd elem from forward_list

#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> int_forward_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto cur = int_forward_list.begin(), pre = int_forward_list.before_begin(); cur != int_forward_list.end();){
        if (*cur % 2) {
            cur = int_forward_list.erase_after(pre);
        } else {
            pre = cur;
            ++cur;
        }
    }

    // print result
    for(const auto i : int_forward_list){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}