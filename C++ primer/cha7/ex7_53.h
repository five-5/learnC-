#ifndef EX7_53_H_INCLUDED
#define EX7_53_H_INCLUDED

class Debug{
public:
    constexpr Debug(bool b = true):he(b),io(b),other(b){}
    constexpr Debug(bool h, bool i, bool o):he(h),io(i),other(o){}
    constexpr bool any(){return he || io || other;}

    void set_io(bool b) {io = b;}
    void set_he(bool b) {he = b;}
    void set_other(bool b) {other = b;}

private:
    bool he;    // Ó²¼þ´íÎó
    bool io;    // IO´íÎó
    bool other; // ÆäËû´íÎó
};

#endif // EX7_53_H_INCLUDED
