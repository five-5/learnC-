#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string line, word;
    vector<string> txt;
    ifstream in("Personinfo.txt");
    if(!in)
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    while(getline(in, line)){
        txt.push_back(line);
    }
    for(auto &s : txt){
        istringstream record(s);
        while(record >> word)
            cout << word << endl;
    }
    return 0;
}
