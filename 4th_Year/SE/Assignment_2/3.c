#include <stdio.h>
int a;

int main() /*@globals undef a @*/
{
	int b;
	b = a;
	return 0;
}