#include <iostream>
#include <cstddef>
using namespace std;

size_t func(int a)
{
    static size_t ctr = 0;   // ���ý��������ֵ��Ȼ��Ч
    size_t local = 0;
    cout << "�β� a = " << a << endl;
    cout << "�ֲ����� local = " << local << endl;
    cout << "�ֲ���̬���� ctr = " << ctr << endl;

    ++ctr;
    ++local;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << func(i*i) << endl;

    return 0;
}
