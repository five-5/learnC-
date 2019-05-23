/*
 * @Author: five-5
 * @Date: 2019-05-23
 * @Description: test exer 15.20
 * @LastEditTime: 2019-05-23
 */

#include "ex15_20.h"

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;   // ok
    p = &d2;         // inaccessible
    p = &d3;         // inaccessible
    p = &dd1;        // ok
    p = &dd2;        // inaccessible
    p = &dd3;        // inaccessible

    return 0;
}