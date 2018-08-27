#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 从标准输入中一次读入一整行
    string line;
    getline(cin, line);
    cout << line << endl;


    cin.sync();

    // 一次读入一个词
    string word;
    cin >> word;
    cout << word << " ";


    return 0;
}
