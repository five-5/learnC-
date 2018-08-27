#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 读入两个字符串
    string str1, str2;
    cout << "Enter a string：" << endl;
    getline(cin, str1);
    cout << "Enter a another string：" << endl;
    getline(cin, str2);

    // 比较
    // 是否等长
    if (str1.size() == str2.size())
    {
        cout << "str1 and str2 have the same length" << endl;
    } else if (str1.size() > str2.size()){
        cout << "the longer string is " << str1 << endl;
    } else{
        cout << "the longer string is " << str2 << endl;
    }

    // 是否相等
    if (str1 > str2)
    {
        cout << "the bigger one is " << str1 << endl;
    } else{
        cout << "the bigger one is " << str1 << endl;
    }

    return 0;
}
