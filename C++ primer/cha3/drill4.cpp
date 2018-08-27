#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char toHex(int number);

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

    // 把0到15之间的十进制数转换成对应的十六进制形式
    // 个人版
    int n;
    string result;
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    while (cin >> n){
        if (n >= 0 && n <= 15)
        {
            result += toHex(n);
        }
    }
    cout << "Your hex number is: " << result << endl;

    // 书本版
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    result = "";
    string::size_type nu;
    while (cin >> nu)
        if (nu < hexdigits.size())
            result += hexdigits[nu];
    cout << "Your hex number is: " << result << endl;
    return 0;
}

char toHex(int number)
{
    if (number <= 9)
        return '0' + number;
    else{
        switch(number)
        {
            case 10: return 'A';
            case 11: return 'B';
            case 12: return 'C';
            case 13: return 'D';
            case 14: return 'E';
            case 15: return 'F';
        }
    }
}

/*
    固定的转换输出可以设置常量数组
    确定不会小于0的数字设置为无符号数
*/
