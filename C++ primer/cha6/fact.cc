#include "Chapter6.h"

int fact(int val)
{
    int ret = 1;
    while(val > 0){
        ret *= val--;
    }
    return ret;
}
