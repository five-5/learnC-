#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int var[5] = {0, 1, 2, 3, 4};
    int var2[5] = {0, 1, 2, 3, 4};
    bool flag = true;
    for (int i = 0, j = 0; i < 5; i++, j++)
    {
        if (var[i] != var[j])
            flag = false;
    }
    if (flag)
        cout << "var = var2" << endl;
    else
        cout << "var ¡Ù var2" << endl;

    vector<int> intVct(5,1);
    vector<int> intVct1{1,2,3,4,5};

    if (intVct == intVct1)
        cout << "intVct = intVct1" << endl;
    else
        cout << "intVct ¡Ù intVct1" << endl;
    return 0;
}
