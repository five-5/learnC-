#include <iostream>
#include <cstddef>
#include <iterator>
using namespace std;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // °æ±¾1
    cout << "V1: " << endl;
    for (auto & p : ia){
            for (auto q : p)
                cout << q << " ";
            cout << endl;
    }

    // °æ±¾2
    cout << "V2: " << endl;
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }

    // °æ±¾3
    cout << "V3: " << endl;
    for (int (*beg)[4] = begin(ia); beg != end(ia); beg++){
        for (int *p = begin(*beg); p != end(*beg); ++p)
            cout << *p << " ";
        cout << endl;
    }

    return 0;
}
