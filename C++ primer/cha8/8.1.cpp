#include <iostream>
#include <string>
using namespace std;

istream& func(istream &in)
{
    // 从给定流中读取数据
    string buf;
    while(in >> buf)
        // 读取的数据打印在标准输出上
        cout << buf << endl;
    // 对流进行复位
    in.clear();
    return in;
}

int main()
{
    istream& in = func(cin);
    cout << in.rdstate() << endl;
    return 0;
}
