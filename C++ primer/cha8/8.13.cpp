#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

bool valid(const string &str)
{
    return (isdigit(str[0])) && (str.size() == 10);
}

string format(const string &str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
    // 读入信息
    ifstream input("Personinfo.txt");
    if (!input){
        cerr << "No data?!" << endl;
        return -1;
    }
    vector<PersonInfo> people;
    string line, word;
    istringstream record;
    while(getline(input, line)){
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    // 过滤电话号码
    for (const auto &entry : people){
        ostringstream formatted, badNums;
        for(const auto &nums : entry.phones){
            if(!valid(nums)){
                badNums << " " << nums;
            } else{
                formatted << " " << format(nums);
            }
        }

        if(badNums.str().empty())
            cout << entry.name << " "
               << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}
