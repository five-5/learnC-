#include <iostream>
using namespace std;

int compare(int a, const int *b)
{
    return (a>*b)? a:*b;
}

int main()
{
    int ival = 10;
    int ival1 = 11;
    int *ival1Ptr = &ival1;
    cout << "bigger one is " << compare(ival, ival1Ptr);

    return 0;
}
