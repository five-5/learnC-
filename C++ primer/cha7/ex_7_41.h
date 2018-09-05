#ifndef EX_7_41_H_INCLUDED
#define EX_7_41_H_INCLUDED

#include <string>
#include <iostream>

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data{
	public:
		// constructor
		Sales_data(const std::string &s, unsigned n, double p) :
				   bookNo(s), units_sold(n), revenue(p*n){std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;}

        // delegating constructor
        Sales_data():Sales_data("", 0, 0){ std::cout << "Sales_data()" << std::endl;}
        Sales_data(const std::string &s):Sales_data(s, 0, 0.0f){std::cout << "Sales_data(const std::string&)" << std::endl; }
        Sales_data(std::istream &is)
        {
             std::cout << "Sales_data(istream &is)" << std::endl;
             read(is, *this);
        }

		// before
		std::string const& isbn() const{ return bookNo;}
		Sales_data& combine(const Sales_data&);

	private:
		inline double avg_price() const;

	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;

	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
};

// member function
inline
double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// non-member functions
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif // EX_7_41_H_INCLUDED
