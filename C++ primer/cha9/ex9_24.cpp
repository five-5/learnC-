// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.24 :
// Use at/[]/front/begin get first elem of vector

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> str_vector = {"first", "seconde"};
    std::cout << "str_vector.at(0) = " << str_vector.at(0) << std::endl;
    std::cout << "str_vector[0] = " << str_vector[0] << std::endl;
    std::cout << "str_vector.front = " << str_vector.front() << std::endl;
    std::cout << "str_vector.begin = " << *str_vector.begin() << std::endl;
    return 0;
}