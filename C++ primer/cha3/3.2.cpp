#include <iostream>
#include <string>
using namespace std;

int main()
{
    // �ӱ�׼������һ�ζ���һ����
    string line;
    getline(cin, line);
    cout << line << endl;


    cin.sync();

    // һ�ζ���һ����
    string word;
    cin >> word;
    cout << word << " ";


    return 0;
}
