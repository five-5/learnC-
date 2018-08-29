#include <iostream>
#include "Chapter6.h"
using namespace std;

int main()
{
    int num;
    cout << "Enter an integer: ";
    while(cin >> num){
        cout << num << "! = " << fact(num) << endl;
        cout << "Enter an integer: ";
    }
    return 0;
}
