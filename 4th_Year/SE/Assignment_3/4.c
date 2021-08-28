#include <stdio.h>
#include <string.h>

//modification
void setx(int *x, int *y) /*@modifies *x@*/
{
    *y = *x;
}
void sety(int *x, int *y) /*@modifies *y@*/
{
    setx(y, x);
}

//global variables
int glob1, glob2;
int f(void) /*@globals glob1;@*/
{
    return glob2;
}



//Require and Ensure Clauses
void strcpy(char *s1, char *s2)
    /*@modifies *s1@*/
    /*@requires maxSet(s1) >=3 @*/
    /*@ensures maxRead(s1) >= maxRead(s2) @*/;
void updateEnv(char *str1)
{
    char *tmp;
    tmp = "MYENV";

    str1 = "i";
    if (tmp != NULL)
        strcpy(str1, tmp);
}