#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s("some string");
    // ����һ����ĸ��д
    if ( !s.empty())
        s[0] = toupper(s[0]);
    cout << s << endl;

    // ����һ���ʴ�д(�Լ���д��)
    int i = 0;
    while (s[i] != ' '){
        s[i] = toupper(s[i]);
        i++;
    }
    cout << s << endl;

    s = "some string";
    cout << s << endl;
    // ���е�д��
    // ���δ���s�е��ַ�ֱ�����Ǵ�����ȫ���ַ���������һ���հ�
    for (decltype(s.size()) index = 0;
         index != s.size() && !isspace(s[index]); ++index)
         s[index] = toupper(s[index]);
    cout << s << endl;

    return 0;
}
