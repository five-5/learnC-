#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    // string对象会自动忽略开头的空白（即空格符、换行符、制表符等）并从第一个真正的字符开始读起，直到遇见下一处空白为止。
    cin >> s;
    cout << s << endl;

    cin.sync(); // 放弃缓存区数据

    // 读取已知数量的string对象
    string s1, s2;
    cin >> s1 >> s2;         // 把第一个输入读到s1中，第二个输入读到s2中
    cout << s1 << s2 <<endl; // 输出两个string对象

    cin.sync(); // 放弃缓存区数据

    // 读取未知数量的string对象
    string word;
    while (cin >> word)      // 反复读取，直至到达文件末尾
        cout << word << endl;// 逐个输出单词，每个单词后面紧跟一个换行

    cin.sync(); // 放弃缓存区数据

    // 保留输入的空白符-- getline
    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return 0;
}
