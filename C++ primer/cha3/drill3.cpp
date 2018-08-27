#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str("some string");
    // 每行输出str中的一个字符
    for (auto c : str)            // 对于str中的每个字符
        cout << c << endl;       // 输出当前字符，后面紧跟一个换行符

    string s("Hello World!!!");
    // punch_cnt的类型和s.size的返回类型一样
    decltype(s.size()) punch_cnt = 0;
    // 统计s中标点符号的数量
    for (auto c : s)
        if (ispunct(c))
            ++punch_cnt;
    cout << punch_cnt
         << "punctuation characters in " << s << endl;

    // 改变字符串中的字符
    // 转换成大写形式
    for (auto &c : s)       // 如果不定义为引用，无法修改
        c = toupper(c);
    cout << s << endl;

    return 0;
}
