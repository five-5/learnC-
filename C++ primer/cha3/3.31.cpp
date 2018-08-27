#include <iostream>
#include <cstddef>
using namespace std;

int main()
{
    int var[10] = {};
    for (size_t i = 0; i < 10; i++)
        var[i] = i;
    for(auto i : var)
        cout << i << " ";

    return 0;
}
