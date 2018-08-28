#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

#define MAX 100

int main()
{
    vector<int> intVct{0, 1, 2};
    int var[MAX] = {};
    size_t size = intVct.size();

    for (vector<int>::size_type i = 0; i < size; i++)
        var[i] = intVct[i];

    cout << "Original vector: ";
    for (auto i : intVct)
        cout << i << " ";
    cout << endl;

    cout << "Copy array: ";
    for (size_t i = 0; i < size; ++i)
        cout << var[i] << " ";
    cout << endl;

    return 0;
}
