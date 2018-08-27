#include <iostream>
#include <string>
using namespace std;

string sa[10];
int ia[10];

int main()
{
    string sa2[10];
    int ia2[10];

    cout << "sa = ";
    for (int i = 0; i < 10; i++)
        cout << sa[i] << " ";
    cout << endl;

    cout << "sa2 = ";
    for (int i = 0; i < 10; i++)
        cout << sa2[i] << " ";
    cout << endl;

    cout << "ia = ";
    for (int i = 0; i < 10; i++)
        cout << ia[i] << " ";
    cout << endl;

    cout << "ia2 = ";
    for (int i = 0; i < 10; i++)
        cout << ia2[i] << " ";
    cout << endl;
    return 0;
}
