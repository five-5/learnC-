#include "ex7_6.h"

using namespace std;

int main()
{
    Sales_data data1;
    Sales_data data2("0-24851-175-X");
    Sales_data data3("0-24851-175-X", 2, 25.0);
    cout << "Enter Sales_data data:" << endl;
    Sales_data data4(cin);

    print(cout, data1) << " data1" << endl;
    print(cout, data2) << " data2" << endl;
    print(cout, data3) << " data3" << endl;
    print(cout, data4) << " data4" << endl;
}
