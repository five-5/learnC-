#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    vector<string> text;
    string line;
    while(getline(cin, line)){
        text.push_back(line);
    }

    for (auto it = text.begin();
         it != text.end() && !it->empty(); ++it){
         for(auto itr = (*it).begin(); itr != (*it).end(); ++itr )
            *itr = toupper(*itr);
        cout << *it ;
    }
    return 0;
}
