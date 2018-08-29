#include <iostream>

using namespace std;

int sum(initializer_list<int> val)
{
    int sum = 0;
    for (auto it = val.begin(); it != val.end(); ++it)
        sum += *it;
    return sum;
}

int main()
{
    int val, val1, val2, val3;
    cout << "Please enter four integers: ";
    cin >> val >> val1 >> val2 >> val3;
    cout << "Sum = " << sum({val, val1, val2, val3});
    return 0;
}
