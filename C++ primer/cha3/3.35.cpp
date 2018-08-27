#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int var[5] = {0,1,2,3,4};
    int *beg = begin(var);
    int *en = end(var);

    for (; beg < en; ++beg)
        *beg = 0;
    for(auto i : var)
        cout << i << " ";

    return 0;
}
