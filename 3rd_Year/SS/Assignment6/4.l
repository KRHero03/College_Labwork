%{
#include <stdio.h>
#include <math.h>
#include <string.h>
void check(char*);
%}
  
%%
[0-9]+ {check(yytext);}
"\n" {return 0;}
%% 
int yywrap(){};
int main()
{
    yylex();
  
    return 0;
}
void check(char* a)
{
    int len = strlen(a), i, num = 0;
    for (i = 0; i < len; i++)
        num = num * 10 + (a[i] - '0');
  
    int x = 0, y = 0, temp = num;
    while (num > 0) {
        y = (int)pow((double)(num % 10),(double) len);
        x = x + y;
        num = num / 10;
    }
  
    if (x == temp)
        printf("%d is an Armstrong number!\n", temp);
    else
        printf("%d is not an Armstrong number!\n", temp);
}