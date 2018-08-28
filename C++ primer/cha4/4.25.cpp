#include <iostream>
using namespace std;

int main()
{
    cout << (~'q' << 6); // 11111111 1111111 11100011 10000000
    return 0;
}
