#include <iostream>
using namespace std;

int main()
{
    typedef int int_array[4];
    int_array a = {0, 1, 2, 3};
    for (auto i : a)
        cout << i << " ";

    return 0;
}
