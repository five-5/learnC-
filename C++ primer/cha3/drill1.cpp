#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    // string������Զ����Կ�ͷ�Ŀհף����ո�������з����Ʊ���ȣ����ӵ�һ���������ַ���ʼ����ֱ��������һ���հ�Ϊֹ��
    cin >> s;
    cout << s << endl;

    cin.sync(); // ��������������

    // ��ȡ��֪������string����
    string s1, s2;
    cin >> s1 >> s2;         // �ѵ�һ���������s1�У��ڶ����������s2��
    cout << s1 << s2 <<endl; // �������string����

    cin.sync(); // ��������������

    // ��ȡδ֪������string����
    string word;
    while (cin >> word)      // ������ȡ��ֱ�������ļ�ĩβ
        cout << word << endl;// ���������ʣ�ÿ�����ʺ������һ������

    cin.sync(); // ��������������

    // ��������Ŀհ׷�-- getline
    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return 0;
}
