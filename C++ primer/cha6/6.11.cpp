#include <iostream>
using namespace std;

void reset(int &val)
{
    val = 0;
}

int main()
{
    int ival;
    cout << "Enter an integer: ";
    cin >> ival;
    cout << "origin: " << endl;
    cout << "ival = " << ival << endl;

    reset(ival);
    cout << "After reset: " << endl;
    cout << "ival = " << ival << endl;
    return 0;
}
