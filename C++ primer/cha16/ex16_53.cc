/*
 * @Author: five-5
 * @Date: 2019-06-17
 * @Description: exer for ex16.53
 * @LastEditTime: 2019-06-17
 */

#include <iostream>
#include <string>

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
} 

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    int i = 0;
    double d = 1;
    float f = 2;
    char c = 'a';
    std::string s = "hello";
    
    print(std::cout, i, d, f, c, s) << std::endl;
    print(std::cout, i) << std::endl;
    print(std::cout, i, c) << std::endl;

    return 0;
}
