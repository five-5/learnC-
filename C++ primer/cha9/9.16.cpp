// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.16 :
// compare list<int> and vector<int>

#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    list<int> int_list = {1, 3, 5, 7, 9};
    vector<int> int_vector1 = {1, 3, 5, 7, 9};
    vector<int> int_vector2 = {1, 3, 9};

    // like string-style
    cout << "int_list == int_vector1? " << (vector<int>(int_list.cbegin(), int_list.cend()) == int_vector1 ? "true": "false") << endl;

    cout << "int_list == int_vector2? " << (vector<int>(int_list.cbegin(), int_list.cend()) == int_vector2 ? "true": "false") << endl;


    return 0;
}