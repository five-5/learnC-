#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 读入多个字符串
    string line, str1, str2;
    while (getline(cin, line)){
        // 连接
        str1 += line;
        // 用空格把输入的多个字符串分隔
        str2 += line + " ";
    }

    cout << str1 << endl;
    cout << str2 << endl;

    return 0;
}
