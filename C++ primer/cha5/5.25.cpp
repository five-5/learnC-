#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int var1, var2;
    cout << "Please enter two integers: ";
    while (cin >> var1 >> var2){
        try{
            if (var2 == 0)
                throw runtime_error("divisor is zero!!!");
            cout << var1 / var2 << endl;
        } catch (runtime_error err){
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n' )
                break;
        }

    }

    return 0;
}
