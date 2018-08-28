#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

int main()
{
    char str1[] = "good morning,";
    char str2[] = "my deal";
    char result[MAX];

    strcpy(result, str1);
    strcat(result, str2);
    cout << "origin : str1 = " << str1 << " str2 = " << str2 << endl;
    cout << "After strcat : " << result << endl;
    return 0;
}
