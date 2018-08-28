#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string currWord, word;
    vector<string> words;
    vector<int> cnts;
    bool flag = false;
    int maxn = 1, flagn = 0;

    if (cin >> currWord){
        int cnt = 1, nu = 0;
        //cout << "currWord = " << currWord << endl;
        while(cin >> word){
                //cout << "word = " << currWord << endl;
            if (currWord == word){
                 ++cnt;
                 flag = true;
            } else{
                words.push_back(currWord);
                cnts.push_back(cnt);
                if (cnt > maxn)
                    flagn = nu;
                nu++;
                cnt = 1;
                currWord = word;
            }
        }
    } else{
        cout << "enter error" << endl;
        return -1;
    }

    if (flag){
        cout << words[flagn] << " 连续出现了 " << cnts[flagn] << " 次";
    } else{
        cout << "任何单词都没有连续出现过";
    }

    return 0;
}

/*
how now now now brown cow cow
*/
