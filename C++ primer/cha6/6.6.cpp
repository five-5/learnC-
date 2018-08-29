#include <iostream>
#include <cstddef>
using namespace std;

size_t func(int a)
{
    static size_t ctr = 0;   // 调用结束后，这个值仍然有效
    size_t local = 0;
    cout << "形参 a = " << a << endl;
    cout << "局部变量 local = " << local << endl;
    cout << "局部静态变量 ctr = " << ctr << endl;

    ++ctr;
    ++local;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << func(i*i) << endl;

    return 0;
}
