#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> intVct;
    int ivar;
    while(cin >> ivar)
        intVct.push_back(ivar);

    cout << "origin: ";
    for (auto i : intVct)
        cout << i << " ";
    cout << endl;

    for (auto &i : intVct)
        (i % 2 == 1)?i *= 2:i;

    cout << "After : ";
    for (auto i : intVct)
        cout << i << " ";
    cout << endl;

    return 0;
}
