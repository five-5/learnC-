#include <iostream>
#include <string>
using namespace std;

istream& func(istream &in)
{
    // �Ӹ������ж�ȡ����
    string buf;
    while(in >> buf)
        // ��ȡ�����ݴ�ӡ�ڱ�׼�����
        cout << buf << endl;
    // �������и�λ
    in.clear();
    return in;
}

int main()
{
    return 0;
}
