#ifndef EX7_5_H_INCLUDED
#define EX7_5_H_INCLUDED

#include <string>

class Person{
    string const& getName() const{ return name;};
    string const& getAddr() const{ return addr;};
    std::string name;
    std::string addr;
};


#endif // EX7_5_H_INCLUDED
