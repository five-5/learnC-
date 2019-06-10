/*
 * @Author: five-5
 * @Date: 2019-06-10
 * @Description: exer for ex16.7
 * @LastEditTime: 2019-06-10
 */

#include <iostream>
#include <vector>
#include <string>

template <typename T, unsigned size>
constexpr unsigned getSize(const T(&)[size]) {
    return size;
}

int main()
{
    int a[5];
    std::cout << "size of int arr is " << getSize(a) << "\n";

    std::vector<int> vecArr[6];
    std::cout << "size of vector arr is " << getSize(vecArr) << "\n";
    
    std::string s[3];
    std::cout << "size of string arr is " << getSize(s) << "\n";

    return 0;
}