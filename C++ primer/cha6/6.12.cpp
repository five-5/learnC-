#include <iostream>
using namespace std;

void swap(int &val1, int &val2)
{
    int tmp;
    tmp = val1;
    val1 = val2;
    val2 = tmp;
}

int main()
{
    int ival1, ival2;

    cout << "Enter two integers: ";
    cin >> ival1 >> ival2;

    cout << "Before swap:" << endl;
    cout << "ival1 = " << ival1 << endl;
    cout << "ival2 = " << ival2 << endl;

    swap(ival1, ival2);

    cout << "After swap: " << endl;
    cout << "ival1 = " << ival1 << endl;
    cout << "ival2 = " << ival2 << endl;

    return 0;
}
