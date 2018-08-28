#include <iostream>
using namespace std;

// ff fl fi
int main()
{
    char ch, beforeCh = '\0';
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

    while( cin >> noskipws >> ch){
        switch(ch){
    case 'l':
        if (beforeCh == 'f')
            ++flCnt;
        break;
    case 'f':
        if (beforeCh == 'f')
            ++ffCnt;
        break;
    case 'i':
        if (beforeCh == 'f')
            ++fiCnt;
        break;
    default:
        break;
        }
        beforeCh = ch;
    }
    cout << "Number of fi: \t" << fiCnt << '\n'
         << "Number of ff: \t" << ffCnt << '\n'
         << "Number of fl: \t" << flCnt << endl;
    return 0;
}
