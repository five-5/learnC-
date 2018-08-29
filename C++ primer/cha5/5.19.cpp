#include <iostream>
#include <string>
using namespace std;

int main()
{

    do{
        cout << "Please enter two string: ";
        string str1, str2;
        cin >> str1 >> str2;
        cout << ((str1.size() <= str2.size())? str1: str2) << endl;
    } while(cin);
    return 0;
}
