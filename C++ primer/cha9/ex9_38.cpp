// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.38 :
// Test for the increment method of g++ vector

#include <iostream>
#include <vector>

const int kTimes = 10;
const int kNum = 5;

void print_info(const std::vector<int> &ivec) {
    std::cout << " ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
}

int main()
{
    std::vector<int> ivec;
    print_info(ivec);

    for (size_t j = 0; j < kTimes; ++j) {
        std::cout << "*" << j << std::endl;
        for (size_t i = 0; i < kNum; ++i) {
            ivec.push_back(i);
            print_info(ivec);
        }
    }
      
    return 0;
}