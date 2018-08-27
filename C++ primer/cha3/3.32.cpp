#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

int main()
{
    // 数组版
    int var[10] = {};
    for (size_t i = 0; i < 10; i++)
        var[i] = i;
    cout << "var = ";
    for(auto i : var)
        cout << i << " ";
    cout << endl;

    // 拷贝数组
    int var1[10];
    for (size_t i = 0; i < 10; i++)
        var1[i] = var[i];
    cout << "var1 = ";
    for(auto i : var1)
        cout << i << " ";
    cout << endl;

    // vector版
    vector<int> intVct;
    for (vector<int>::size_type i = 0; i < 10; i++)
        intVct.push_back(i);
    vector<int> intVct1 = intVct;

    cout << "intVct = ";
    for (auto it = intVct.cbegin(); it != intVct.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "intVct1 = ";
    for (auto it = intVct1.cbegin(); it != intVct1.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
