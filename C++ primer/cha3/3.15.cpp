#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> vctStr;
    string str;
    while (cin >> str)
        vctStr.push_back(str);
    for (int i = 0; i < vctStr.size(); i++)
        cout << vctStr[i] << endl;
    return 0;
}

