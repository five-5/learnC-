#include <iostream>
#include <string>
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
                cout << word << endl;
                flag = true;
                break;
            } else{
                currWord = word;
            }
        }
        if (!flag)
            cout << "no continuous word." << endl;
    } else{
        cout << "error input." << endl;
    }
    return 0;
}
