#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    // string对象
    cout << "string对象：" << endl;
    string str1 = "hello, world";
    string str2 = "my deal";
    if (str1 <= str2)
        cout << str1 << " <= " << str2 << endl;
    else
        cout << str2 << " < " << str1 << endl;
    cout << endl;

    // C风格字符串
    cout << "C风格字符串：" << endl;
    char cstr1[] = "hello, world";
    char cstr2[] = "my deal";
    if (strcmp(cstr1, cstr2) <= 0)
        cout << cstr1 << " <= " << cstr2 << endl;
    else
        cout << cstr2 << " <= " << cstr1 << endl;


    return 0;
}
