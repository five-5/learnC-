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
    // ��ͳfor
    for (i = 0; i < line.size(); i++)
    {
        if (!isdigit(line[i]))       // ��֪���ַ�ֵʲô���ݶ�Ϊ������֮���
            line[i] = 'X';
    }
    cout << line << endl;

    // while
    i = 0;
    while (i < line1.size()){
        if (!isdigit(line1[i]))       // ��֪���ַ�ֵʲô���ݶ�Ϊ������֮���
            line1[i] = 'X';
        i++;
    }
    cout << line1 << endl;
    return 0;
}
