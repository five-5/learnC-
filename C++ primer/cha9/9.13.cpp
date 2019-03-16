#include <list>
#include <vector>
#include <iostream>

void print(const std::vector<double> &vec){
    for(std::vector<double>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it){
        std::cout << *it <<" ";
    }
    std::cout << std::endl;
}

int main()
{
    // list<int> -> vector<double>
    std::list<int> iList = {1, 2, 3, 4, 5};
    std::vector<double> dVec(iList.begin(), iList.end());
    print(dVec);

    // vector<int> -> vector<double>
    std::vector<int> iVec = {6, 7, 8, 9, 10};
    std::vector<double> dVec2(iVec.begin(), iVec.begin() + 3);
    print(dVec2);

    // must be both same can be assigned
    /*
    no suitable user-defined conversion from "std::vector<int, std::allocator<int>>" to "std::vector<double, std::allocator<double>>" exists std::vector<int> iVec
    */
    // std::vector<double> dVec3 = iVec;

    return 0;
}