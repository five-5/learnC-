#include <iostream>

int main()
{
    int val = 10, sum = 0;
    while( val >= 0){
        sum += val;
        val--;
    }
    std::cout << "Sum of 10 to 0 inclusive is "
              << sum << std::endl;
    return 0;
}
