/*
 * @Author: five-5
 * @Description: ex13.5 ex13.8 ex13.11
 * @Date: 2019-05-11
 * @LastEditTime: 2019-05-11
 */



#include <string>

class HasPtr{
 public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0){ }
    
    // copy constructor ex13.5
    HasPtr(const HasPtr& rhs) : ps(new std::string(*rhs.ps)), i(rhs.i){  }

    // cpoy assignment
    HasPtr& operator= (const HasPtr& rhs)
    {
        if (this != &rhs)  // 避免误delete自己
        {
            std::string *temp = new std::string(*rhs.ps);
            delete this->ps;
            this->ps = temp;
            this->i = rhs.i;
        }
        return *this;
    }

    // destructor
    ~HasPtr()
    {
        delete this->ps;
    }

 private:
    std::string *ps;
    int i;
};