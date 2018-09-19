#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // 打开一个文件
    string filename = "input8.4.txt";
    vector<string> vecs;
    ifstream in;
    in.open(filename,ifstream::in);
    if(in){
        string tmp;
        while(getline(in,tmp)){
            vecs.push_back(tmp);
        }
    } else{
        cout << "can't open " << filename << endl;
        in.close();
        return -1;
    }
    in.close();
    for(auto s:vecs)
        cout << s << endl;
    return 0;
}
