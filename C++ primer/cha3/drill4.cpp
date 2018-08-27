#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s("some string");
    // 将第一个字母大写
    if ( !s.empty())
        s[0] = toupper(s[0]);
    cout << s << endl;

    // 将第一个词大写(自己的写法)
    int i = 0;
    while (s[i] != ' '){
        s[i] = toupper(s[i]);
        i++;
    }
    cout << s << endl;

    s = "some string";
    cout << s << endl;
    // 书中的写法
    // 依次处理s中的字符直至我们处理完全部字符或者遇到一个空白
    for (decltype(s.size()) index = 0;
         index != s.size() && !isspace(s[index]); ++index)
         s[index] = toupper(s[index]);
    cout << s << endl;

    return 0;
}
