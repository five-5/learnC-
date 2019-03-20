// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.15 :
// Check two vector equality

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v1 = { 1, 3, 5, 7, 9, 12};
    vector<int> v2 = { 1, 3, 9};
    vector<int> v3 = { 1, 3, 5, 7};
    vector<int> v4 = { 1, 3, 5, 7, 9, 12};

    // string-style compare
    if (v1 == v4) {
        cout << "v1 = v4" << endl;
    } else {
        cout << "v1 != v4" << endl;
    }

    if (v3 < v4) {
        cout << "v3 < v4" << endl;
    } else {
        cout << "v3 >= v4" << endl;
    }

    if (v1 < v2) {
        cout << "v1 < v2" << endl;
    } else {
        cout << "v1 >= v2" << endl;
    }

    return 0;
}