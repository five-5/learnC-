#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int add(int, int);
int substract(int, int);
int multi(int, int);
int divide(int, int);

using Func = decltype(add) *;

int main()
{
    vector<Func> vec{add, substract, multi, divide};
    int a = 5, b = 0;
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    {
        try{
            cout << (*it)(a, b) << endl;
        } catch(runtime_error err){
            cout << err.what() << endl;
        }
    }
    return 0;
}

int add(int a, int b)
{
    return  a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multi(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("divider is zero!!!");
        return -1;
    }
    return a / b;
}


