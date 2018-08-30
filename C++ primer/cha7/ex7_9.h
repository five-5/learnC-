#ifndef EX7_9_H_INCLUDED
#define EX7_9_H_INCLUDED

#include <string>
#include <iostream>

class Person{
    string const& getName() const{ return name;};
    string const& getAddr() const{ return addr;};
    std::string name;
    std::string addr;
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

#endif // EX7_9_H_INCLUDED
