// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.34 :
// test for the function of code page317 ex9.34
// 
// *Result:
// #case 1. if you have good code style and open the -Wall option, it will warning like this: 
// ex9_34.cpp:18:5: warning: this ‘while’ clause does not guard... [-Wmisleading-indentation]
//     while (iter != vi.end())
//     ^~~~~
//ex9_34.cpp:21:9: note: ...this statement, but the latter is misleadingly indented as if it were //guarded by the ‘while’
//         ++iter;
//         ^~
//
// #case 2: dead-loop
// #case 3: dead-loop
// it should be modified like #case4

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    /* case 1.
    while (iter != vi.end()) 
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;
    */

   /* case 2.
    while (iter != vi.end()) 
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
    ++iter;
    */

   /* case 3.
    while (iter != vi.end()) {
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;
    }
    */

   /* case 4.*/
    while (iter != vi.end()) {
        if (*iter % 2){
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else {
            ++iter;
        }
    }
    
    for(const auto i : vi){
        std::cout << i << " ";
    }

    return 0;
}