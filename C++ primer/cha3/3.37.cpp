#include <iostream>
using namespace std;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }

    return 0;
}

/*
�е��ɻ�Ϊʲô���кü��εĽ������һ����
*/
