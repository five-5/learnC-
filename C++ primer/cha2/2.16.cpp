#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    // (a)
    r2 = 3.14159;
    std::cout << "r2 = " << r2 << std::endl;
    // (b)
    r2 = r1;
    std::cout << "r2 = " << r2 << std::endl;
    // (c)
    i = r2;
    std::cout << "i = " << i << std::endl;
    // (d)
    r1 = d;
    std::cout << "r1 = " << r1 << std::endl;
}
