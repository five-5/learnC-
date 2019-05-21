/*
 * @Author: five-5
 * @Date: 2019-05-21
 * @Description: simple calculator test
 * @LastEditTime: 2019-05-21
 */

#include <map>
#include <string>
#include <functional>
#include <iostream>

// 普通函数
int add(int a, int b) {
    return a + b;
}

// lambda
auto mod = [](int a, int b) {return a % b;};

// 函数对象类
struct divide {
    int operator() (int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},                                       // 函数指针
        {"-", std::minus<int>()},                         // 标准库函数对象
        {"/", divide()},                                  // 用户定义的函数对象
        {"*", [](int a, int b) {return a * b;}},          // 未命名的lambda
        {"%",mod}                                         // 命名了的lambda对象
    };
    
    while (std::cout << "Please enter as: num operator num :\n", true)
    {
        int lhs, rhs;
        std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }
    
    return 0;
}
