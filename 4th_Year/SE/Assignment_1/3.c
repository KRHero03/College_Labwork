#include <stdio.h>
typedef /*@abstract@*/ char *mstring;
typedef /*@abstract@*/ bool bool;
int isPalindrome(mstring s){
    char *current = (char *)s;
    int i, len = (int)strlen(s);
    for (i = 0; i <= (len + 1) / 2; i++){
        if (current[i] != s[len - i - 1]) return 0;
    }
    return 1;
}

bool callPal(void){
    return (isPalindrome("bob"));
}
