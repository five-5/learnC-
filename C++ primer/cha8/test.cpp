#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 刷新输出缓冲区联系 endl、flush、ends
    cout << "hi!" << endl; // 输出hi和换行，刷新缓冲区
    cout << "hi!" << flush; // 输出i，刷新缓冲区
    cout << "1" << endl;
    cout << "hi!" << ends; // 输出hi和一个空字符，然后刷新缓冲区
    cout << "2" << endl;

    //unitbuf操作符
    cout << unitbuf;    // 所有输出操作后都会立即刷新缓冲区
    // 任何输出都立即刷新，无缓冲
    cout << nounitbuf;  // 回到正常的缓冲方式

    // 关联输入和输出流
    string s;
    cin >> s;
    cout << "hello test" << endl;
    cout << s << endl;
    return 0;
}
