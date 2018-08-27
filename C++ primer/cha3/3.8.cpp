#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string line, line1;
    getline(cin, line);
    line1 = line;
    string::size_type i;
    // 传统for
    for (i = 0; i < line.size(); i++)
    {
        if (!isdigit(line[i]))       // 不知道字符值什么，暂定为除数字之外的
            line[i] = 'X';
    }
    cout << line << endl;

    // while
    i = 0;
    while (i < line1.size()){
        if (!isdigit(line1[i]))       // 不知道字符值什么，暂定为除数字之外的
            line1[i] = 'X';
        i++;
    }
    cout << line1 << endl;
    return 0;
}
