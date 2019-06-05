/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: test Query
 * @LastEditTime: 2019-06-05
 */

#include "WordQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"

#include <fstream>

int main()
{
    std::ifstream file("test.txt");
    TextQuery tQuery(file);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q.eval(tQuery) << std::endl;
    return 0;
}