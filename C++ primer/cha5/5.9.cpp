#include <iostream>
using namespace std;

int main()
{
    unsigned vowelCnt = 0;
    char ch;
    while (cin >> ch){
        switch(ch){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                ++vowelCnt;
                break;
            default:
                break;
        }
    }
    cout << "the number of vowel = " << vowelCnt;
    return 0;
}
