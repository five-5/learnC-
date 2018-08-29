#include <iostream>
using namespace std;

int main()
{
    // (a)
    do{
        int v1, v2;
        cout << "Please enter two numbers to sum:";
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while(cin);

    // (c)
    do{
        int ival = 10;
    } while(ival);


    return 0;
}
