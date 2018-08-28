#include <iostream>

using namespace std;

int main()
{
    unsigned long ul1 = 3, ul2 = 7;

    // (a)
    cout << "(a) " << (ul1 & ul2) << endl;

    // (b)
    cout << "(b) " << (ul1 | ul2) << endl;

    // (c)
    cout << "(c) " << (ul1 && ul2) << endl;

    // (a)
    cout << "(d) " << (ul1 || ul2) << endl;

    return 0;
}
