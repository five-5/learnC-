#include <iostream>
using namespace std;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char ch;
    // cin要使用noskipws，noskipws会告诉istream读取字符时不要跳过空白符。
    while (cin >> noskipws >> ch){
        switch(ch){
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            default:
                break;
        }
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of space: \t" << spaceCnt << '\n'
         << "Number of tab: \t" << tabCnt << '\n'
         << "Number of newline: \t" << newlineCnt << endl;
    return 0;
}
