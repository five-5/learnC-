#include <iostream>
using namespace std;

void swap(int *(&a), int *(&b))
{
    int *tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {5, 6, 7, 8, 9};

    cout << "a = ";
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    cout << "b = ";
    for (auto i : b)
        cout << i << " ";
    cout << endl;

    cout << "After : " << endl;

    swap(a, b);

    cout << "a = ";
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    cout << "b = ";
    for (auto i : b)
        cout << i << " ";
    cout << endl;

    return 0;
}
