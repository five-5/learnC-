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
有点疑惑为什么运行好几次的结果都是一样的
*/
