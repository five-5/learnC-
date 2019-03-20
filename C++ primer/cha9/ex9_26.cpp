// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.26 :
// Using the following definition of ia, copy it to a vector and a list
// Use the single-iterator form to erase odd elem from list and even elem from vector

#include <iostream>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    
    // non-member begin() and end()
    std::vector<int> int_vector(std::begin(ia), std::end(ia));
    std::list<int> int_list(std::begin(ia), std::end(ia));

    for(auto it = int_vector.begin(); it != int_vector.end();){
        if (*it % 2 == 0) {
            it = int_vector.erase(it);
        } else {
            ++it;
        }
    }

    for(auto it = int_list.begin(); it != int_list.end();){
        if (*it & 0x01) {
            it = int_list.erase(it);
        } else {
            ++it;
        }
    }

    // print result
    cout << "list : ";
    for(auto i : int_list){
        cout << i << " ";
    }

    cout << endl << "vector : ";
    for(auto i : int_vector){
        cout << i << " ";
    }

    return 0;
}