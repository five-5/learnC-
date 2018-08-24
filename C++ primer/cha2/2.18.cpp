#include <iostream>

int main()
{
    int *ptr = nullptr;
    int a = 1, b = 3;
    ptr = &a;
    (*ptr)++;
    std::cout << a << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    ptr = &b;
    std::cout << *ptr << std::endl;
    return 0;
}
