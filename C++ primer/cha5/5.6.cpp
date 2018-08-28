#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
F: 60ртоб
D: 60-70
C: 70-80
B: 80-90
A: 90
A++: 100
*/

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    while (cin >> grade){
        string lettergrade;
        lettergrade = (grade < 60)? scores[0]:scores[(grade - 50) / 10];

        cout << lettergrade << endl;
    }

    return 0;
}
