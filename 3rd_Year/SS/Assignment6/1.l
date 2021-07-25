%{
#include<stdio.h>
int lines=0,words = 0, characters = 0,cnt=0;
%}
  
%%
[a-zA-Z0-9_!$_#%^*] {cnt++;characters++;}
" " {if(cnt!=0){words++;cnt=0;}characters++;}				
[\t] words++;
[\n] {words++;lines==0?lines=2:lines++;}			
%%
  
int yywrap(){}
int main(){
  
  
FILE *fp;
char filename[50];
printf("Enter the filename: ");
scanf("%s",filename);
fp = fopen(filename,"r");
yyin = fp;
  
yylex();
     
printf("No. of lines=%d\n", lines); 
printf("No. of words=%d\n", words);
printf("No. of characters=%d\n", characters);
  
return 0;
}