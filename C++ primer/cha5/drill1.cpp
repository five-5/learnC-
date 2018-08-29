#include <iostream>
#include "./cha1/Sales_item.h"
#include <stdexcept>
using namespace std;

int main()
{
    Sales_item item1, item2;
    cin >> item1 >> item2;
    /*
     * exercise the use of throw
    */
    // First check two book whether have the same ISBN
    if (item1.isbn() != item2.isbn())
        throw runtime_error("Data must refer to same ISBN");
    // if program run to here, it infer that two book have the same ISBN
    cout << item1 + item2 << endl;


    // try-catch exercise
    while(cin >> item1 >> item2){
        try{
            // code about item to add

        } catch(runtime_error err){
            // print the error info and ask whether input again
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}
