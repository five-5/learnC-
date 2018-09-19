#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
    void print(){
        cout << name << " ";
        for(auto &phone : phones)
            cout << phone << " ";
        cout << endl;
    }
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream in("Personinfo.txt");
    if(!in)
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    while(getline(in, line)){
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for(auto person:people)
        person.print();
    return 0;
}
