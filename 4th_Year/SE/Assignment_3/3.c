#include <stdio.h>

extern int square( int x);
#define square(x) ((x) * (x))

extern int sumsquares(int x, int y);
#define sumsquares(x, y) (square(x) + square(y))

int main()
{
    int i = 1;
    i = square(i++);
    i = sumsquares(i, i);

    printf("Checking Macro implementation and invocations\n");
    return 0;
}