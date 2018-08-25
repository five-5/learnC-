#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    a = 42;
    std::cout << "a = " << a << std::endl;

    b = 42;
    std::cout << "b = " << b << std::endl;

    c = 42;
    std::cout << "c = " << c << std::endl;

    d = 42;  // invalid conversion from 'int' to 'int*'
    std::cout << "d = " << d << std::endl;

    e = 42; // invalid conversion from 'int' to 'int*'
    std::cout << "e = " << e << std::endl;

    g = 42; // assignment of read-only reference 'g'
    std::cout << "g = " << g << std::endl;

    return 0;
}
