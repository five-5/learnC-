#include <iostream>
#include <cstddef>
using namespace std;

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; ++i)
            cout << argv[i] << " ";

    return 0;
}
