#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ���������ַ���
    string str1, str2;
    cout << "Enter a string��" << endl;
    getline(cin, str1);
    cout << "Enter a another string��" << endl;
    getline(cin, str2);

    // �Ƚ�
    // �Ƿ�ȳ�
    if (str1.size() == str2.size())
    {
        cout << "str1 and str2 have the same length" << endl;
    } else if (str1.size() > str2.size()){
        cout << "the longer string is " << str1 << endl;
    } else{
        cout << "the longer string is " << str2 << endl;
    }

    // �Ƿ����
    if (str1 > str2)
    {
        cout << "the bigger one is " << str1 << endl;
    } else{
        cout << "the bigger one is " << str1 << endl;
    }

    return 0;
}
