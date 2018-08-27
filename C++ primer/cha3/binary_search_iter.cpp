#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string sought;
    cout << "Please enter the string you search: ";
    cin >> sought;
    vector<string> text{"ha","his","hi","what","where"};
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2;

    while(mid != end && *mid != sought){
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }

    if (mid == end)
        cout << "Can not find the string " << sought;
    else
        cout << "Find it!";
    return 0;
}
