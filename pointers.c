#include <stdio.h>
#include <stdlib.h>

int main() {

    int x, y, *pt;

    x = 5;
    pt = &x;
    y = *pt;

    printf("X: %d, Y: %d, Pointer: %p \n", x, y, pt);

}