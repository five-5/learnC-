#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vctInt;
    int temp;
    while (cin >> temp)
        vctInt.push_back(temp);
    for (temp = 0; temp < vctInt.size(); temp++)
        cout << vctInt[temp] << endl;
    return 0;
}
