#include <stdio.h>

void updateEnv(char *str)
{
    char *tmp;
    tmp = getenv("MYENV");
    if (tmp != NULL)
        strcpy(str, tmp);
}

void updateEnvSafe(char *str, size_t strSize) /*@requires maxSet(str) >= strSize @*/
{
    char *tmp;
    tmp = getenv("MYENV");
    if (tmp != NULL)
    {
        strncpy(str, tmp, strSize - 1);
        str[strSize - 1] = '/0';
    }
}

int main()
{
    printf("Buffer Owerflow attack\n");
    return 0;
}