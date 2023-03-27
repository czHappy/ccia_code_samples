#include <stdio.h>
#include "head.h"

int main(){
    int a = 10, b = 2; 
    printf("%d\n", add(a, b));
    printf("%d\n", sub(a, b));
    printf("%d\n", mult(a, b));
    printf("%d\n", div(a, b));
    
    return 0;
}