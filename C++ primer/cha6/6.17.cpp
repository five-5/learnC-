#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// judge string whether has capital
bool hasCapital(const string &s)
{
    for (auto it = s.cbegin(); it != s.cend(); ++it)
        if (isupper(*it))
            return true;
    return false;
}

// change the string to lower case
void toLow(string &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
        if (isupper(*it))
            *it = tolower(*it);
}

int main()
{
    string str = "Hello world";
    cout << str << (hasCapital(str)? "has capital":"doesn't have capital") << endl;
    cout << str << " lower case is ";
    toLow(str);
    cout << str;

    return 0;
}
