// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.45 :
// accept strname and prefix and suffix use insert and append to add to name

#include <iostream>
#include <string>

std::string add_pre_and_suf(
    const std::string &str_name, 
    const std::string &prefix, 
    const std::string &suffix) {
        std::string str_temp = str_name;
        str_temp.insert(str_temp.begin(), prefix.begin(), prefix.end());
        str_temp.append(suffix);
        return str_temp;
}

int main()
{
    std::string str_name = "five-5", prefix = "Ms.", suffix = "III";
    std::cout << add_pre_and_suf(str_name, prefix, suffix);
    
    return 0;
}