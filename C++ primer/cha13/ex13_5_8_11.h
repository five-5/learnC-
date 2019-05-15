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

    // move constructor
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
        p.ps = nullptr;
        p.i = 0;
    }

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

    // copy and swap
    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }

    // swap
    inline void swap(HasPtr& lhs, HasPtr& rhs) {
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
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