#include <iostream>

int main()
{
    // (a)
    int input_value;
    std::cin >> input_value;

    // (b)
    int i = { 3.14 };
    std::cout << "(b)i = " << i << std::endl;

    // (c)
    // double salary = wage = 9999.99; error: 'wage' was not declared in this scope
    double salary = 9999.99, wage = salary;
    std::cout << "(c) salary = " << salary << " wage = " << wage << std::endl;

    // (d)
    int id = 3.14;
    std::cout << "(d)i = " << id << std::endl;

    return 0;
}
