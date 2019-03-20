// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.31.1 :
// page 316 delete even elem copy odd elem can't apply to list modify it to apply

#include <iostream>
#include <list>

int main()
{
    std::list<int> int_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = int_list.begin();
    while (iter != int_list.end()) {
        if (*iter % 2 == 0) {
            iter = int_list.erase(iter);
        } else {
            iter = int_list.insert(iter, *iter);
            std::advance(iter, 2);                          // vector support it += n;
        }
    }

    // print result
    for (const auto i : int_list) {
        std::cout << i << " ";
    }

    return 0;
}