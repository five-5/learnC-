#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ˢ�������������ϵ endl��flush��ends
    cout << "hi!" << endl; // ���hi�ͻ��У�ˢ�»�����
    cout << "hi!" << flush; // ���i��ˢ�»�����
    cout << "1" << endl;
    cout << "hi!" << ends; // ���hi��һ�����ַ���Ȼ��ˢ�»�����
    cout << "2" << endl;

    //unitbuf������
    cout << unitbuf;    // ������������󶼻�����ˢ�»�����
    // �κ����������ˢ�£��޻���
    cout << nounitbuf;  // �ص������Ļ��巽ʽ

    // ��������������
    string s;
    cin >> s;
    cout << "hello test" << endl;
    cout << s << endl;
    return 0;
}
