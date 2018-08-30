#include <iostream>
#include <string>
using namespace std;

// define the structure of Sales_data
struct Sales_data
{
    string bookNo;          // ISBN
    unsigned units_sold = 0;// book's sales
    double revenue = 0.0;   // total income
};

int main()
{
    Sales_data total;
    if (cin>> total.bookNo >> total.units_sold >> total.revenue){
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if (total.bookNo == trans.bookNo){
                total.revenue += trans.revenue;
                total.units_sold += trans.units_sold;
            } else{
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else{
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
