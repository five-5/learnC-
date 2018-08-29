#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string currWord, word;
    bool flag = false;

    if (cin >> currWord)
    {
        while (cin >> word){
            if ( word == currWord)
            {
                if (word[0] == toupper(word[0]))
                {
                    cout << word << endl;
                    flag = true;
                    break;
                } else {
                    currWord = word;
                    continue;
                }
            } else{
                currWord = word;
            }
        }
        if (!flag)
            cout << "no continuous word start with capital." << endl;
    } else{
        cout << "error input." << endl;
    }
    return 0;
}
