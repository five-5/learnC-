#include <iostream>
using namespace std;

int main()
{
    unsigned grade;
    cout << "Please enter your grade(>0): ";
    cin >> grade;

    // ���������
    cout << ((grade > 90)?"high pass":(grade > 75)?"pass":(grade < 60)?"fail":"low pass");
    cout << endl;

    // if���
    if (grade > 90)
        cout << "high pass";
    else if (grade > 75)
        cout << "pass";
    else if (grade < 60)
        cout << "fail";
    else
        cout << "low pass";

    return 0;
}
