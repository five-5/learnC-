/*
 * @Author: five-5
 * @Description: ex13_13
 * @Date: 2019-05-11
 * @LastEditTime: 2019-05-11
 */

#include <iostream>
#include <vector>

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X& operator=(const X&) {std::cout << "X& operator=(const X&)" << std::endl; return *this;}
    ~X() { std::cout<<"~X()" << std::endl;}

};

void testRef(const X& x) {}
void testNonRef(const X x) {}

int main()
{
    X x;
    std::cout << "-------start test" << std::endl;
    std::cout << "-testRef start" << std::endl;
    testRef(x);
    std::cout << "-end testRef" << std::endl;
    
    std::cout << "-testNonRef start" << std::endl;
    testNonRef(x);
    std::cout << "-end testNonRef " << std::endl;

    std::cout << "-test dynamic allocate start" << std::endl;

    X* x1 = new X();
    std::cout << "-end test dynamic allocate" << std::endl;

    std::cout << "-test vec start" << std::endl;
    std::vector<X> vecX;
    vecX.push_back(*x1);
    std::cout << "-end test vec" << std::endl;
    
    std::cout << "-----------end of test" << std::endl;
    return 0;
}