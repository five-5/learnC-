#include <iostream>
#include <string>
using namespace std;

int main()
{
    // �������ַ���
    string line, str1, str2;
    while (getline(cin, line)){
        // ����
        str1 += line;
        // �ÿո������Ķ���ַ����ָ�
        str2 += line + " ";
    }

    cout << str1 << endl;
    cout << str2 << endl;

    return 0;
}
