/*
 * @Author: five-5
 * @Date: 2019-05-23
 * @Description: exer for 15.20
 * @LastEditTime: 2019-05-23
 */
#ifndef EX15_20_H
#define EX15_20_H
class Base {
 public:
    void pub_mem();
    void memfcn(Base &b) { b = *this; }
 protected:
    int prot_mem;
 private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};


struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
    void memfcn(Base &b) { b = *this; }   // illegal
};

#endif