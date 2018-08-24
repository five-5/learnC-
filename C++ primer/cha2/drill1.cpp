#include <iostream>

int main()
{
    int test = 0;
    int test1 = {1};
    int test2{2};
    int test3(3);

    std::cout << "test = " << test << std::endl;
    std::cout << "test1 = " << test1 << std::endl;
    std::cout << "test2 = " << test2 << std::endl;
    std::cout << "test3 = " << test3 << std::endl;
    return 0;
}
