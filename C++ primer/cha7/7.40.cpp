#include <iostream>
#include <string>
using namespace std;

class Book{
public:
    Book(string bname, string bisbn, string bwriter, string bpublisher, double bprice):
        name(sname), isbn(bisbn), writer(bwriter), publisher(bpublisher), price(bprice){}
    Book(istream &is)
    {
        is >> name >> isbn >> writer >> publisher >> price;
    }
    Book(){}

private:
    string name;
    string isbn;
    string writer;
    string publisher;
    double price;
};
