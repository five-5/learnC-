#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    int var[] = {0, 1, 2};
    vector<int> copyVct(begin(var), end(var));
    vector<int> partVct(var, var+2);

    cout << "Original array: ";
    for (auto i : var)
        cout << i << " ";
    cout << endl;

    cout << "Copy vector: ";
    for (auto i : copyVct)
        cout << i << " ";
    cout << endl;

    cout << "Part vector: ";
    for (auto it = partVct.cbegin(); it != partVct.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
