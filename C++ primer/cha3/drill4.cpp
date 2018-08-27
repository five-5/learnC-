#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char toHex(int number);

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

    // ��0��15֮���ʮ������ת���ɶ�Ӧ��ʮ��������ʽ
    // ���˰�
    int n;
    string result;
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    while (cin >> n){
        if (n >= 0 && n <= 15)
        {
            result += toHex(n);
        }
    }
    cout << "Your hex number is: " << result << endl;

    // �鱾��
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    result = "";
    string::size_type nu;
    while (cin >> nu)
        if (nu < hexdigits.size())
            result += hexdigits[nu];
    cout << "Your hex number is: " << result << endl;
    return 0;
}

char toHex(int number)
{
    if (number <= 9)
        return '0' + number;
    else{
        switch(number)
        {
            case 10: return 'A';
            case 11: return 'B';
            case 12: return 'C';
            case 13: return 'D';
            case 14: return 'E';
            case 15: return 'F';
        }
    }
}

/*
    �̶���ת������������ó�������
    ȷ������С��0����������Ϊ�޷�����
*/
