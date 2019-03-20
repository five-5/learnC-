// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.41 :
// Construct string from vector<char>



#include <iostream>
#include <vector>
#include <string>


int main()
{
    std::vector<char> cvec = {'i','n','i','t',' ','s','t','r',' ','b','y',' ','c','v','e','c'};
    std::string str(cvec.cbegin(), cvec.cend());
    std::cout << str << std::endl;
    return 0;
}