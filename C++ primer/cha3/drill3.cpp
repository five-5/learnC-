#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str("some string");
    // ÿ�����str�е�һ���ַ�
    for (auto c : str)            // ����str�е�ÿ���ַ�
        cout << c << endl;       // �����ǰ�ַ����������һ�����з�

    string s("Hello World!!!");
    // punch_cnt�����ͺ�s.size�ķ�������һ��
    decltype(s.size()) punch_cnt = 0;
    // ͳ��s�б����ŵ�����
    for (auto c : s)
        if (ispunct(c))
            ++punch_cnt;
    cout << punch_cnt
         << "punctuation characters in " << s << endl;

    // �ı��ַ����е��ַ�
    // ת���ɴ�д��ʽ
    for (auto &c : s)       // ���������Ϊ���ã��޷��޸�
        c = toupper(c);
    cout << s << endl;

    return 0;
}
