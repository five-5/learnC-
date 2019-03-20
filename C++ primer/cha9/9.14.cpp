// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.14 :
// Write a program to assign the elements from a list of char * pointers to C-style chararcter strings

#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::list, std::vector, std::string, std::cout, std::endl;

int main()
{
    list<char *> char_list{"hello", "my", "ex", "9.14"};
    vector<string> str_vector;
    // warning: ISO C++ forbids converting a string constant to ‘char*’
    str_vector.assign(char_list.cbegin(), char_list.cend());

    // @CppCoreGuidelines
    // 1. prefer a range-for-statement;
    // 2. don't use expensive copies of the loop variable
    for (const auto &str : char_list)
    {
        cout << str << endl;
    }

    return 0;
}