#include <iostream>

int main()
{
    int sum = 0;
    // ´Ó1¼Óµ½10
    for (int i = -100; i <= 100; i++)
        sum += i;
    std::cout << "Sum of -100 to 100 inclusive is "
              << sum << std::endl;
    return 0;
}
