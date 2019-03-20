// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.40 :
// Test for the ex9.39
// 
// Result
//n = 256
// ivec: size: 384 capacity: 1024
//n = 512
// ivec: size: 768 capacity: 1024
//n = 1000                                  1000的时候直接根据resize1500 所以空间不够在1000的基础上翻倍
// ivec: size: 1500 capacity: 2000
//n = 1048
// ivec: size: 1572 capacity: 2048          1024的时候添加不够，所以翻倍为2048


#include <iostream>
#include <vector>
#include <string>


void print_info(const std::vector<std::string> &ivec) {
    std::cout << " ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
}

int main()
{
    std::vector<int> ivec = {256, 512, 1000, 1048};
    for(const auto n : ivec){
        std::vector<std::string> svec;
        svec.reserve(1024);
        std::string word;
        /*while (std::cin >> word)*/
        for(int i = 0; i < n; ++i){
            word = std::to_string(i);
            svec.push_back(word);
        }
        svec.resize(svec.size() + svec.size()/2);
        std::cout << "n = " << n << std::endl;
        print_info(svec);
    }
      
    return 0;
}