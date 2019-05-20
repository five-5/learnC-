/*
 * @Author: five-5
 * @Date: 2019-05-20
 * @Description: exer for ex13.27, ex13.30, ex13.31
 * @LastEditTime: 2019-05-20
 */

#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
        return *(lhs.ps) < *(rhs.ps);
    }

 public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // 拷贝构造函数
    HasPtr(const HasPtr &p):
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
        

    void swap(HasPtr &rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }

    HasPtr& operator=(HasPtr rhs) {
        // ++*rhs.use;       // 递增右侧运算对象的引用计数
        // if (--*use == 0) {
        //     delete ps;
        //     delete use;
        // }
        // ps = rhs.ps;
        // i = rhs.i;
        // use = rhs.use;
        // return *this;       // 返回本对象

        // swap version
        this->swap(rhs);
        return *this;
        
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

    void show() const {
        std::cout << *ps << std::endl;
    }

 private:
    std::string *ps;
    int i;
    std::size_t *use;   // 用来记录有多少个对象共享*ps的成员
};
 
void swap(HasPtr &lhs, HasPtr &rhs) {
        lhs.swap(rhs);
        std::cout << "call friend swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    }

#endif