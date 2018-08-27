#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str, str1;
    getline(cin, str);

    for (auto c : str){
        if (!ispunct(c))
           str1 += c;
    }

    cout << str1 << endl;
    return 0;
}
