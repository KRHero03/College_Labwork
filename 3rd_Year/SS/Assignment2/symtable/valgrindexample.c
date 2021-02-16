/*
  Author: Diana Palsetia
  Date: 11/30/09
  Description: Example for Valgrind
*/
#include <stdlib.h>
int main()
{
        int *p, i;
        p = malloc(5*sizeof(int));
        for(i = 0;i < 5;i++){
                p[i] = i;

        }
 //       free(p);
//        free(p);
        return 0;

}

