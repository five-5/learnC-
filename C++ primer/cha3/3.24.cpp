#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> intVct(11,0);
    int var;
    while (cin >> var){
        auto it = intVct.begin();
        (*(it + var / 10 ))++;
    }

    for (auto it = intVct.cbegin(); it != intVct.cend(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}

/*
42 65 95 100 39 67 95 76 88 76 83 92 76 93
*/
