#include <iostream>
using namespace std;

int abs(int val)
{
    return (val > 0)? val: (-val);
}

int main()
{
    int num;
    cout << "enter an integer: ";
    while(cin >> num){
        cout << "abs(" << num << ") = " << abs(num) << endl;
        cout << "enter an integer: ";
    }

    return 0;
}
