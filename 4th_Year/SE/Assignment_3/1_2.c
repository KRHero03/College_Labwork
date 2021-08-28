#include <stdio.h>

typedef enum { TYPE1, TYPE2, TYPE3, TYPE4, TYPE5 } ynm;

void decide(ynm y)
{
    switch (y)
    {
    /*@fallthrough@*/
    case TYPE1:
        break;
    case TYPE2:
        printf("Type2!");
    case TYPE3:
        printf("Type3");
        break;
    case TYPE4:
    case TYPE5:
        printf("Type4");
        break;
    }
}

int main()
{
    printf("Checking fall through switch cases");
    return 0;
}