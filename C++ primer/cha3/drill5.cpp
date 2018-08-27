#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : v)
        i *= i;
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // 一组成绩集合，0-100，统计11个分数段的数量
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade){
        if (grade <= 100)
            ++scores[grade/10];
    }
    for (vector<int>::size_type i = 0; i < scores.size(); ++i)
        cout << scores[i] << " ";

    return 0;
}
/*
42 65 95 100 39 67 95 76 88 76 83 92 76 93
*/
