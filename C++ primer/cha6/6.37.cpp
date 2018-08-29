#include <string>
using namespace std;
using Str = string (&)[10];

Str func(Str &s);
auto func1(Str &s) -> string (&)[10];

string arrS[10];
decltype(arrS)& func2(Str &s);


