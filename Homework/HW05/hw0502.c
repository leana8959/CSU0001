#include <stdio.h>
#include "mymemcmp.h"

int main(){
    char buffer1[] = "hello";
    char buffer2[] = "hellop";
    int diff = mymemcmp(buffer1, buffer2, 6);
    printf("%d", diff);
}
