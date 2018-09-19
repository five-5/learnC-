#include <iostream>
#include <sstream>
using namespace std;

istream& func(istream &is)
{
    string buf;
    while(is >> buf)
        cout << buf << endl;
    is.clear();
    return is;
}

int main()
{
    istringstream iss("hello world");
    func(iss);
    return 0;
}
