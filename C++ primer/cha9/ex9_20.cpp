// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.20 :
// Copy even elem from list to one deque, odd elem to another deque

#include <iostream>
#include <list>
#include <deque>

int main()
{
    std::list<int> int_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> odd_deque, even_deque;

    for(const auto int_val : int_list){
        if (int_val % 2) {
            odd_deque.push_back(int_val);
        } else {
            even_deque.push_back(int_val);
        }
    }

    std::cout << "odd elem : ";
    for(const auto odd : odd_deque){
        std::cout << odd << " ";
    }

    std::cout << std::endl << "even elem : ";
    for(const auto even : even_deque){
        std::cout << even << " ";
    }

    return 0;
}