// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.19 :
// Rewrite ex9.18 with list. 
// just change the type

#include <iostream>
#include <string>
#include <list>

int main()
{
    
    std::list<std::string> str_list;
    for(std::string word; std::cin >> word; str_list.push_back(word));
    
    for(const auto &str : str_list){
        std::cout << str << std::endl;
    }
    return 0;
}

