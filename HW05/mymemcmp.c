#include "mymemcmp.h"

int mymemcmp(const char *str1, const char *str2, size_t num){

    unsigned char *comp1 = str1;
    unsigned char *comp2 = str2;
    
    while (num > 0)
    {
        if (*comp1 != *comp2)
            return (*comp1 - *comp2);
        num--;
        comp1++;
        comp2++;
    }
    return 0;
}