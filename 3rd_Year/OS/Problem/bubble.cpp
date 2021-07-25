#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <cstdlib>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{
    int  ch;
    int temp = atoi(argv[1]);
    int p[temp];
    for (int i = 0; i < temp; i++)
        p[i] = rand();
    struct timeval tp1, tp2;
    gettimeofday( &tp1, NULL);
    for (int i = 0; i < temp - 1; i++)
        for (int j = i; j < temp; j++)
            if (p[j] > p[j + 1])
            {
                ch = p[j];
                p[j] = p[j + 1];
                p[j + 1] = ch;
            }
    gettimeofday(&tp2, NULL);
    cout << (tp2.tv_sec - tp1.tv_sec) * 1000000 + (tp2.tv_usec - tp1.tv_usec) << endl;
    return 0;
}