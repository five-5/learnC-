#include <iostream>
using namespace std;

int main()
{
    int i;
    double d;

    // (a)
    d = i = 3.5;
    cout << "i = " << i << " d = " << d << endl;

    // (b)
    i = d = 3.5;
    cout << "i = " << i << " d = " << d << endl;

    return 0;
}
