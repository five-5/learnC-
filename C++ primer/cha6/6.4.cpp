#include <iostream>
using namespace std;

int fact(int val)
{
    int ret = 1;
    while (val > 0)
        ret *= val--;
    return ret;
}

int main()
{
    int num;
    cout << "enter an integer: ";
    while(cin >> num){
        cout << num << "! = " << fact(num) << endl;
        cout << "enter an integer: ";
    }

    return 0;
}
