#include <iostream>
#include <iterator>
#include <cstddef>
using namespace std;

void print(const int *a, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << " ";
    count << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    i = end(j) - begin(j);
    print(j, i);
    print(begin(j), end(j));
    return 0;
}
