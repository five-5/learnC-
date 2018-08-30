#ifndef EX7_15_H_INCLUDED
#define EX7_15_H_INCLUDED

#include <string>
#include <iostream>

class Person{

    public:
		// constructor
		Person() = default;
		Person(const string &Name, const string &Addr):name(Name), addr(Addr){}
        Person(std::istream &is){ read(is, *this);}

		string const& getName() const{ return name;};
		string const& getAddr() const{ return addr;};

    private:
		std::string name;
		std::string addr;

    friend std::istream& read(std::istream &is, Person &person);
    friend std::ostream& print(std::ostream &os, const Person &person);
};

// non-member functions
std::istream& read(std::istream &is, Person &person)
{
    is >> person.name >> person.addr;
    return is;
}

std::ostream& print(std::ostream &os, const Person &person)
{
    os << person.getName() << " " << person.getAddr();
    return os;
}

#endif // EX7_15_H_INCLUDED
