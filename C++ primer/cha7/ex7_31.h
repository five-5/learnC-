#ifndef EX7_31_H_INCLUDED
#define EX7_31_H_INCLUDED

class Y;

class X{
    private:
        Y* ptrY = nullptr;
};

class Y{
    private:
        X x;
};

#endif // EX7_31_H_INCLUDED
