int func(int, int);

using pFunc1 = decltype(func) *;
using pFunc2 = int *(int, int);
using pFunc3 = int (int, int);
typedef int (*pFunc4)(int, int);
typedef decltype(func) *pFunc5;

vector<pFunc1> vec;
vector<pFunc2> vec;
vector<pFunc3*> vec;
vector<pFunc4> vec;
vector<pFunc5> vec;
