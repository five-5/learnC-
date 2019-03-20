// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.18 :
// read strings to store in deque and print elem

#include <iostream>
#include <string>
#include <deque>

int main()
{
    
    std::deque<std::string> str_deque;
    for(std::string word; std::cin >> word; str_deque.push_back(word));
    
    for(const auto &str : str_deque){
        std::cout << str << std::endl;
    }
    return 0;
}