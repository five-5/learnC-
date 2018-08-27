#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Please enter even number of integers: ";
    vector<int> intVct;
    int var;
    while (cin >> var)
        intVct.push_back(var);

    // Êä³öÏàÁÚ
    for (auto it = intVct.cbegin(); it != intVct.cend(); it = it + 2){
        cout << *it << " + " << *(it+1) << " = " << (*it) + (*(it+1)) << endl;
    }

    // Ê×+Î²
    auto end = intVct.cend() - 1;
    for (auto it = intVct.cbegin(); it - end <= 0; ++it, --end){
        cout << *it << " + " << *(end) << " = " << (*it) + (*end) << endl;
    }

    return 0;
}


