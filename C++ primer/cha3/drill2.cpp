#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    // string����Ƚ�
    if (str <= phrase)
        cout << str << " < " << phrase <<endl;
    if (slang >= phrase)
        cout << slang << " > " << phrase <<endl;

    // string����ֵ
    string st1(10, 'c'), st2; // st1����Ϊ10��c;st2Ϊ���ַ���
    cout << "��ֵǰ��" << endl;
    cout << "st1 = " << st1 << " " << "����Ϊ��" << st1.size() << endl;
    cout << "st2 = " << st2 << " " << "����Ϊ��" << st2.size() << endl;

    st1 = st2; // ��ֵ����st2�ĸ����滻st1�����ݣ���ʱ��Ϊ���ַ���
    cout << "��ֵ��" << endl;
    cout << "st1 = " << st1 << " " << "����Ϊ��" << st1.size() << endl;
    cout << "st2 = " << st2 << " " << "����Ϊ��" << st2.size() << endl;

    // ����string�������
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + '\n';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = s1 + ', '+ s2 = " << s3;

    return 0;
}
