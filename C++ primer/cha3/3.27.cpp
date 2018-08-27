#include <iostream>
using namespace std;

int txt_size()
{
    return 1;
}

int txt_size1()
{
    int a = 1;
    return a;
}

int main()
{
    int ia[txt_size()];
    int ib[txt_size1()];
    return 0;
}
