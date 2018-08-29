#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int var1, var2;
    cout << "Please enter two integers: ";
    cin >> var1 >> var2;
    if (var2 == 0)
        throw runtime_error("divisor is zero!!!");
    cout << var1 / var2 << endl;

    return 0;
}
