#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
F: 60以下
D: 60-70
C: 70-80
B: 80-85
A: 85-90
A++: 90以上
*/

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    while (cin >> grade){
        string lettergrade;
        if (grade < 60)
            lettergrade = scores[0];
        else if (grade < 80)
            lettergrade = scores[(grade - 50) / 10];
        else if (grade < 90)
            lettergrade = scores[(grade - 80) / 5 + 3];
        else
            lettergrade = scores[5];

        cout << lettergrade << endl;
    }

    return 0;
}
