#ifndef EX7_57_H_INCLUDED
#define EX7_57_H_INCLUDED

#include <string>

class Account{
public:
    coid calculate(){amount += amount * interestRate;}
    static double rate(){return interestRate;}
    static void rate(double newRate) {interestRate = newRate;}

private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr todayRate = 42.42;
    static double initRate(){return todayRate;}
};

double Account::interestRate = initRate();

#endif // EX7_57_H_INCLUDED
