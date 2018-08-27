#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s("some string");
    if (s.begin() != s.end()){
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;

    s = "some string";
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << s << endl;
    return 0;
}
