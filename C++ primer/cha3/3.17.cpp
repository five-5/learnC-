#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    vector<string> strVct;
    string word;
    while(cin >> word){
        strVct.push_back(word);
    }
    for (auto v : strVct){
        for(auto &w : v){
            w = toupper(w);
        }
        cout << v << endl;
    }


    return 0;
}
