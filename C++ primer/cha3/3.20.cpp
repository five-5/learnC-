#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> intVct;
    cout << "Please enter even number of integers:" << endl;
    int temp;
    while(cin >> temp){
        intVct.push_back(temp);
    }

    vector<int>::size_type length = intVct.size();
    for(vector<int>::size_type i = 0; i < length; i++)
    {
        cout << intVct[i] << " + " << intVct[i+1] << " = " << intVct[i] + intVct[i+1] << endl;
        i++;
    }

    for(vector<int>::size_type i = 0; i < length / 2; i++)
    {
        cout << intVct[i] << " + " << intVct[length-1-i] << " = " << intVct[i] + intVct[length-1-i] << endl;
    }
    return 0;
}
