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
        if (!isdigit(c))       // ��֪���ַ�ֵʲô���ݶ�Ϊ������֮���
            c = 'X';
    }
    cout << line << endl;
    return 0;
}
