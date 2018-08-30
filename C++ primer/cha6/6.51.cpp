#include <iostream>
using namespace std;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    // f(2.56, 42); ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    f(5.2);
    return 0;
}

void f()
{
    cout << "f()" << endl;
}

void f(int a)
{
    cout << "f(int) parameter: " << a << endl;
}

void f(int a, int b)
{
    cout << "f(int, int) parameter: " << a << " " << b << endl;
}

void f(double a, double b)
{
    cout << "f(double, double = 3.14) parameter: " << a << " " <<  b << endl;
}
