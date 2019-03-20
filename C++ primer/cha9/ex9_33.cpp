// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.33 :
// test the the invalid of iterator

#include <iostream>
#include <vector>

int main()
{
    /*
        double free or corruption (out)
        Aborted (core dumped)
    */
    std::vector<int> int_vector(10,0);
    auto begin = int_vector.begin();
    while (begin != int_vector.end()) {
        ++begin;
        int_vector.insert(begin, 42);
        ++begin;
    }
    
    return 0;
}