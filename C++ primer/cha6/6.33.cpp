#include <iostream>
#include <vector>
using namespace std;
using Iter = vector<int>::const_iterator;

void print(Iter beg, Iter end)
{
    if(beg != end)
    {
        cout << *beg << " ";
        print(++beg, end);
    }
}

int main()
{
    vector<int> vec;
    int val;
    while(cin >> val)
        vec.push_back(val);

    print(vec.cbegin(), vec.cend());

    return 0;
}
