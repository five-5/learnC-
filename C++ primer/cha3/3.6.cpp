#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    for (auto &c : line)
    {
        if (!isdigit(c))       // 不知道字符值什么，暂定为除数字之外的
            c = 'X';
    }
    cout << line << endl;
    return 0;
}
