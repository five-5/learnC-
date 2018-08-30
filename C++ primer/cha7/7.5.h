#include <string>
using namespace std;
using Cstr = string const&;

class Person{
    Cstr getName() const{return name;};
    Cstr getAddr() const{return addr;};
    string name;
    string addr;
};

