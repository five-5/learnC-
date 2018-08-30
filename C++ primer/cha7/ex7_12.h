#ifndef EX7_12_H_INCLUDED
#define EX7_12_H_INCLUDED

#include <string>
#include <iostream>

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data{
	public:
		// constructor
		Sales_data() = default;
		Sales_data(const std::string &s) : bookNo(s){}
		Sales_data(const std::string &s, unsigned n, double p) :
				   bookNo(s), units_sold(n), revenue(p*n){}
		Sales_data(std::istream &is){ read(is, *this);}

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


#endif // EX7_12_H_INCLUDED
