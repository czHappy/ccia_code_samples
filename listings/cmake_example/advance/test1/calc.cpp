#include <stdio.h>
extern "C"{
#include "calc.h"
}
int main(){
    int a = 10, b = 2; 
    printf("%d\n", add(a, b));
    printf("%d\n", sub(a, b));
    printf("%d\n", mult(a, b));
    printf("%d\n", div(a, b));

#ifdef DEBUG
    printf("calc test, open debug macro.\n");
#endif

    return 0;
}